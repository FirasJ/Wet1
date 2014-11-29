
#include "iDroid.h"

iDroid::iDroid() : _versions(), _appsByIDtree(), _appsByDLtree(), _max() {
}

StatusType iDroid::AddVersion(int versionCode) {
	if ( versionCode <= 0 ) return INVALID_INPUT;
	if ( !_versions.empty() && versionCode != _versions.getTail().getId()+1 ) return FAILURE;
	_versions.insert(Version(versionCode));
	return SUCCESS;
}

StatusType iDroid::AddApplication(int appID, int versionCode, int downloadCount) {
	if ( appID <= 0 || versionCode <= 0  || downloadCount < 0 ) return INVALID_INPUT;
	try {
		bool found = false;
		for(List<Version>::Iterator it = _versions.begin(); it != _versions.end(); ++it) {
			if(it->getId() == versionCode) {
				found = true;
				DataByID byId(appID, versionCode, downloadCount);
				DataByDowns byDowns(appID, versionCode, downloadCount);
				_appsByIDtree.insert(byId);
				_appsByDLtree.insert(byDowns);
				it->_appsByIDtree.insert(byId);
				it->_appsByDLtree.insert(byDowns);
				if (byDowns > it->_max) {
					it->_max = byDowns;
				}
				if (byDowns > _max) {
					_max = byDowns;
				}
			}
		}
		if(!found) return FAILURE;
	} catch(Tree<DataByID>::ElementAlreadyExists& e) {
		return FAILURE;
	} catch(Tree<DataByDowns>::ElementAlreadyExists& e) {
		return FAILURE;
	}
	return SUCCESS;
}

StatusType iDroid::RemoveApplication(int appID) {
	if ( appID <= 0 ) return INVALID_INPUT;
	try {
		DataByID appByID(appID);
		Tree<DataByID>::Node* node = _appsByIDtree.find(appByID);
		appByID = node->getData();
		_appsByIDtree.remove(appByID);
		DataByDowns appByDowns(appByID);
		_appsByDLtree.remove(appByDowns);

		int version = appByID._versionCode;
		List<Version>::Iterator it = _versions.find(Version(version));
		assert(it != _versions.end());
		it->_appsByIDtree.remove(appByID);
		it->_appsByDLtree.remove(appByDowns);
		_max = getMax(_appsByDLtree);
		it->_max = getMax(it->_appsByDLtree);
	} catch(Tree<DataByID>::TreeIsEmpty& e) {
		return FAILURE;
	} catch(Tree<DataByID>::ElementNotFound& e) {
		return FAILURE;
	} catch(Tree<DataByDowns>::ElementNotFound& e) {
		return FAILURE;
	}
	return SUCCESS;
}

DataByDowns iDroid::getMax(Tree<DataByDowns>& tree) {
	try {
		return tree.getMax()->getData();
	} catch (Tree<DataByDowns>::TreeIsEmpty& e) {
		return DataByDowns();
	}
}

StatusType iDroid::IncreaseDownloads(int appID, int downloadIncrease) {
	if ( appID <= 0 || downloadIncrease <= 0 ) return INVALID_INPUT;
	try {
		DataByID appByID(appID);
		Tree<DataByID>::Node* node = _appsByIDtree.find(appByID);
		appByID = node->getData();
		StatusType status = RemoveApplication(appID);
		if(status != SUCCESS) return status;
		appByID._downloads += downloadIncrease;
		status = AddApplication(appID, appByID._versionCode , appByID._downloads);
		if(status != SUCCESS) return status;
	} catch(Tree<DataByID>::ElementNotFound& e) {
		return FAILURE;
	} catch(Tree<DataByDowns>::ElementNotFound& e) {
		return FAILURE;
	}
	return SUCCESS;
}

StatusType iDroid::UpgradeApplication(int appID) {
	if ( appID <= 0 ) return INVALID_INPUT;
	try {
		DataByID appByID(appID);
		Tree<DataByID>::Node* node = _appsByIDtree.find(appByID);
		if(node->getData()._appID != appID) { // element not found
			return FAILURE;
		}
		Version version(node->getData()._versionCode);
		List<Version>::Iterator it = _versions.find(version);

		if ( ++it == _versions.end() ) return FAILURE;
		it = _versions.find(version);

//		if(*it == _versions.getTail()) return FAILURE;

		appByID = node->getData();
		DataByDowns appByDowns(appByID);

		StatusType status = RemoveApplication(appID);
		if(status != SUCCESS) return status;
		status = AddApplication(appID, it->_versionID +1 , appByID._downloads);
		if(status != SUCCESS) return status;

	}  catch(Tree<DataByID>::TreeIsEmpty& e) {
		return FAILURE;
	}  catch(Tree<DataByDowns>::TreeIsEmpty& e) {
		return FAILURE;
	}
	return SUCCESS;
}

StatusType iDroid::GetTopApp(int versionCode, int* appID) {
	*appID = -1;
	if(versionCode == 0 || !appID) {
		return INVALID_INPUT;
	} else if(versionCode < 0) {
		/*if(_max._appID <= 0) { // empty
			return SUCCESS;
		}*/
		*appID = _max._appID;
		return SUCCESS;
	}
	List<Version>::Iterator it = _versions.find(Version(versionCode));
	if(it == _versions.end()) {
		return FAILURE;
	}
	*appID = it->_max._appID;
	return SUCCESS;
}

StatusType iDroid::GetAllAppsByDownloads(int versionCode, int** apps, int* numOfApps) {
	if(!apps || !numOfApps || versionCode == 0) {
		return INVALID_INPUT;
	}
	if(versionCode < 0) {
		return getAllApps(_appsByDLtree, apps, numOfApps);
	} else {
		List<Version>::Iterator it = _versions.find(Version(versionCode));
		if(it == _versions.end()) {
			return FAILURE;
		}
		return getAllApps(it->_appsByDLtree, apps, numOfApps);
	}
}

class TreeToArray {
	int** apps;
	int* numOfApps;
	int index;
public:
	TreeToArray(int** apps, int* numOfApps) : apps(apps), numOfApps(numOfApps), index(*numOfApps-1) {}
	void operator()(const DataByDowns& data) {
		(*apps)[index] = data.getAppId();
		--index;
	}
};

StatusType iDroid::getAllApps(const Tree<DataByDowns>& tree, int** apps, int* numOfApps) {
	assert(apps && numOfApps);
	*numOfApps = tree.size();
	if(tree.size() == 0) {
		*apps = NULL;
		return SUCCESS;
	}
	*apps = (int*)malloc(sizeof(int)*tree.size());
	if(!*apps) {
		return ALLOCATION_ERROR;
	}
	TreeToArray convert(apps, numOfApps);
	tree.inOrder(convert);
	return SUCCESS;
}

void mergeLists(const List<DataByDowns>& list1, const List<DataByDowns>& list2, List<DataByDowns>& newList) {
	List<DataByDowns>::Iterator it1 = list1.begin();
	List<DataByDowns>::Iterator it2 = list2.begin();
	while ( it1 != list1.end() || it2 != list2.end() ) {
		if(*it1 < *it2) {
			newList.insert(*it1);
			++it1;
		} else {
			newList.insert(*it2);
			++it2;
		}
	}
	if( it1 == list1.end() ) {
		while( it2 != list2.end() ) {
			newList.insert(*it2);
			++it2;
		}
		return;
	}
	if( it2 == list2.end() ) {
		while( it1 != list1.end() ) {
			newList.insert(*it1);
			++it1;
		}
		return;
	}
}

class FillTree {
public:
	FillTree(const List<DataByDowns> list) : _current(list.begin()) {}
	void operator()(DataByDowns& data) {
		data = *_current;
		++_current;
	}
private:
	List<DataByDowns>::Iterator _current;

};

class UpdateDL {
public:
	UpdateDL(int groupBase, int multiplyFactor) : _groupBase(groupBase), _multiplyFactor(multiplyFactor) {}
	void operator()(DataByID& data) const {
		if( data._appID%_groupBase == 0 ) {
			data._downloads *= _multiplyFactor;
		}
	}
private:
	int _groupBase, _multiplyFactor;
};

class PredicateTree {
public:
	PredicateTree(List<DataByDowns>* belongs, List<DataByDowns>* doesntBelong, int groupBase, int multiplyFactor) :	_belongs(belongs),
																													_doesntBelong(doesntBelong),
																													_groupBase(groupBase),
																													_multiplyFactor(multiplyFactor) {}
	void operator()(DataByDowns& data) {
		if( data._appID%_groupBase == 0 ) {
			data._downloads *= _multiplyFactor;
			_belongs->insert(data);
		} else {
			_doesntBelong->insert(data);
		}
	}
private:
	List<DataByDowns> *_belongs, *_doesntBelong;
	int _groupBase, _multiplyFactor;
};

void updateTrees(int groupBase, int multiplyFactor, Tree<DataByID>& appsByIDtree, Tree<DataByDowns>& appsByDLtree) {
	UpdateDL updateDL(groupBase, multiplyFactor);
	appsByIDtree.inOrder(updateDL);
	List<DataByDowns> list1, list2, allElements;
	PredicateTree prediacteTree(&list1, &list2, groupBase, multiplyFactor);
	appsByDLtree.inOrder(prediacteTree);
	mergeLists(list1, list2, allElements);
	FillTree fillTree(allElements);
	appsByDLtree.inOrder(fillTree);
}

StatusType iDroid::UpdateDownloads(int groupBase, int multiplyFactor) {
	if ( groupBase < 1 || multiplyFactor <= 0 ) return INVALID_INPUT;

	updateTrees(groupBase, multiplyFactor, _appsByIDtree, _appsByDLtree);
	_max = getMax(_appsByDLtree);

	for(List<Version>::Iterator it = _versions.begin(); it != _versions.end(); ++it) {
		updateTrees(groupBase, multiplyFactor, it->_appsByIDtree, it->_appsByDLtree);
		it->_max = getMax(it->_appsByDLtree);
	}

	return SUCCESS;
}

iDroid::~iDroid() {
}

bool operator <(const DataByID& data1, const DataByID& data2) {
	if (data1._appID > data2._appID) return true;
	return false;
}

bool operator >(const DataByID& data1, const DataByID& data2) {
	if (data1._appID < data2._appID) return true;
	return false;
}

bool operator <(const DataByDowns& data1, const DataByDowns& data2) {
	if (data1._downloads < data2._downloads) return true;
	if (data1._downloads == data2._downloads) {
		if (data1._appID > data2._appID)  {
			return true;
		} else {
			return false;
		}
	}
	return false;
}

bool operator >(const DataByDowns& data1, const DataByDowns& data2) {
	if (data1._downloads > data2._downloads) return true;
	if (data1._downloads == data2._downloads) {
		if (data1._appID < data2._appID) {
			return true;
		} else {
			return false;
		}
	}
	return false;
}

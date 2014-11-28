
#include "iDroid.h"

iDroid::iDroid() : _versions(), _appsByIDtree(), _appsByDLtree(), _max() {
}

StatusType iDroid::AddVersion(int versionCode) {
	if ( versionCode <= 0 ) return INVALID_INPUT;
	if ( versionCode <= _versions.getTail().getId() ) return FAILURE;
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

		if(_max == appByDowns) {
			_max = _appsByDLtree.getMax()->getData();
		}

		int version = appByID._versionCode;
		List<Version>::Iterator it = _versions.find(version);
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

DataByDowns& iDroid::getMax(Tree<DataByDowns>& tree) {
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
		appByID = node->getData();

	}  catch(Tree<DataByID>::ElementNotFound& e) {
		return FAILURE;
	}
	return SUCCESS;
}

StatusType iDroid::GetTopApp(int versionCode, int* appID) {
	if(versionCode < 0) {

		return SUCCESS;
	}
	List<Version>::Iterator it = _versions.find(versionCode);

	return SUCCESS;
}

StatusType iDroid::GetAllAppsByDownloads(int versionCode, int** apps, int* numOfApps) {
	return SUCCESS;
}

StatusType iDroid::UpdateDownloads(int groupBase, int multiplyFactor) {
	return SUCCESS;
}

iDroid::~iDroid() {
}

bool operator <(const DataByID& data1, const DataByID& data2) {
	if (data1._appID < data2._appID) return true;
	return false;
}

bool operator >(const DataByID& data1, const DataByID& data2) {
	if (data1._appID > data2._appID) return true;
	return false;
}

bool operator <(const DataByDowns& data1, const DataByDowns& data2) {
	if (data1._downloads == data2._downloads) {
		if (data1._appID < data2._appID)  {
			return true;
		} else {
			return false;
		}
	}
	if (data1._downloads < data2._downloads) return true;
	return false;
}

bool operator >(const DataByDowns& data1, const DataByDowns& data2) {
	if (data1._downloads == data2._downloads) {
		if (data1._appID > data2._appID) {
			return true;
		} else {
			return false;
		}
	}
	if (data1._downloads > data2._downloads) return true;
	return false;
}

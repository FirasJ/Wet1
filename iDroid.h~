#ifndef IDROID_H_
#define IDROID_H_

#include "library1.h"
#include "list.h"
#include "tree.h"

class DataByID {
public:
	DataByID() :
			_appID(-1), _versionCode(-1), _downloads(-1) {
	}
	DataByID(const DataByID& data) :
			_appID(data._appID), _versionCode(data._versionCode), _downloads(
					data._downloads) {
	}
	DataByID(int id, int versionCode = -1, int downloads = -1) :
			_appID(id), _versionCode(versionCode), _downloads(downloads) {
	}
	bool operator ==(const DataByID& data) {
		return (data._appID == _appID);
	}
	bool operator !=(const DataByID& data) {
		return !(*this == data);
	}
	friend bool operator <(const DataByID& data1, const DataByID& data2);
	friend bool operator >(const DataByID& data1, const DataByID& data2);
	friend class iDroid;
	friend class DataByDowns;
	friend class UpdateDL;
private:
	int _appID, _versionCode, _downloads;
};

class DataByDowns {
public:
	DataByDowns() :
			_appID(-1), _versionCode(-1), _downloads(-1) {
	}
	DataByDowns(int id, int versionCode, int downloads) :
			_appID(id), _versionCode(versionCode), _downloads(downloads) {
	}
	DataByDowns(const DataByDowns& data) :
			_appID(data._appID), _versionCode(data._versionCode), _downloads(
					data._downloads) {
	}
	DataByDowns(const DataByID& data) :
			_appID(data._appID), _versionCode(data._versionCode), _downloads(
					data._downloads) {
	}
	bool operator ==(const DataByDowns& data) {
		return (data._appID == _appID);
	}
	bool operator !=(const DataByDowns& data) {
		return !(*this == data);
	}
	friend bool operator <(const DataByDowns& data1, const DataByDowns& data2);
	friend bool operator >(const DataByDowns& data1, const DataByDowns& data2);

	int getAppId() const {
		return _appID;
	}

	friend class iDroid;
	friend class DataByID;
	friend class PredicateTree;
private:
	int _appID, _versionCode, _downloads;
};

class Version {
public:
	Version() :
			_versionID(0), _appsByIDtree(), _appsByDLtree(), _max() {
	}
	Version(int versionID) :
			_versionID(versionID), _appsByIDtree(), _appsByDLtree(), _max() {
	}
	bool operator ==(const Version& version) {
		return (version._versionID == _versionID);
	}
	int getId() const {
		return _versionID;
	}
	friend class iDroid;
private:
	int _versionID;
	Tree<DataByID> _appsByIDtree;
	Tree<DataByDowns> _appsByDLtree;
	DataByDowns _max;
};

class iDroid {
public:

	iDroid();
	StatusType AddVersion(int versionCode);
	StatusType AddApplication(int appID, int versionCode, int downloadCount);
	StatusType RemoveApplication(int appID);
	StatusType IncreaseDownloads(int appID, int downloadIncrease);
	StatusType UpgradeApplication(int appID);
	StatusType GetTopApp(int versionCode, int *appID);
	StatusType GetAllAppsByDownloads(int versionCode, int **apps,
			int *numOfApps);
	StatusType UpdateDownloads(int groupBase, int multiplyFactor);
	~iDroid();

private:

	List<Version> _versions;
	Tree<DataByID> _appsByIDtree;
	Tree<DataByDowns> _appsByDLtree;
	DataByDowns _max;

	DataByDowns getMax(Tree<DataByDowns>& tree);
	StatusType getAllApps(const Tree<DataByDowns>& tree, int** apps,
			int* numOfApps);
};

#endif /* IDROID_H_ */


#ifndef IDROID_H_
#define IDROID_H_

#include "library1.h"
#include "list.h"
#include "tree.h"

class DataByID {
public:
	DataByID() : _appID(0), _downloads(0), _versionCode(0) {}
	DataByID(const DataByID& data) : _appID(data._appID), _downloads(data._downloads), _versionCode(data._versionCode) {}
//	DataByID(const DataByDowns& data) : _appID(data._appID), _downloads(data._downloads), _versionCode(data._versionCode) {}
	DataByID(int id, int downloads=-1, int versionCode=-1) : _appID(id), _downloads(downloads), _versionCode(versionCode) {}
	bool operator ==(const DataByID& data) {	return (data._appID == _appID);	}
	bool operator !=(const DataByID& data) {	return !(*this == data);	}
	friend bool operator <(const DataByID& data1, const DataByID& data2);
	friend bool operator >(const DataByID& data1, const DataByID& data2);
	friend class iDroid;
	friend class DataByDowns;
private:
	int _appID, _downloads, _versionCode;
};

class DataByDowns {
public:
	DataByDowns() : _appID(0), _downloads(0), _versionCode(0) {}
	DataByDowns(int id, int downloads, int versionCode) : _appID(id), _downloads(downloads), _versionCode(versionCode) {}
	DataByDowns(const DataByDowns& data) : _appID(data._appID), _downloads(data._downloads), _versionCode(data._versionCode) {}
	DataByDowns(const DataByID& data) : _appID(data._appID), _downloads(data._downloads), _versionCode(data._versionCode) {}
	bool operator ==(const DataByDowns& data) {	return (data._appID == _appID);	}
	bool operator !=(const DataByDowns& data) {	return !(*this == data);	}
	friend bool operator <(const DataByDowns& data1, const DataByDowns& data2);
	friend bool operator >(const DataByDowns& data1, const DataByDowns& data2);
	friend class iDroid;
	friend class DataByID;
private:
	int _appID, _downloads, _versionCode;
};

class Version {
public:
	Version() : _versionID(0), _appsByIDtree(), _appsByDLtree(), _max() {}
	Version(int versionID) : _versionID(versionID), _appsByIDtree(), _appsByDLtree(), _max() {}
	bool operator ==(const Version& version) {	return version._versionID == _versionID;	}
	int getId() const {	return _versionID;	}
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
	StatusType GetAllAppsByDownloads(int versionCode, int **apps, int *numOfApps);
	StatusType UpdateDownloads(int groupBase, int multiplyFactor);
	~iDroid();

private:

	List<Version> _versions;
	Tree<DataByID> _appsByIDtree;
	Tree<DataByDowns> _appsByDLtree;
	DataByDowns _max;

};

#endif /* IDROID_H_ */

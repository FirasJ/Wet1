
#include "library1.h"
#include "iDroid.h"

void* Init() {
	iDroid* DS = new iDroid();
	return (void*)DS;
}

#define CHECK_NULL(ptr) if (!ptr) return INVALID_INPUT

StatusType AddVersion(void *DS, int versionCode) {
	CHECK_NULL(DS);
	try {
		return ((iDroid*)DS)-> AddVersion(versionCode);
	} catch(std::bad_alloc& e) {
		return ALLOCATION_ERROR;
	}
}

StatusType AddApplication(void *DS, int appID, int versionCode, int downloadCount) {
	CHECK_NULL(DS);
	try {
		return ((iDroid*)DS)-> AddApplication(appID, versionCode, downloadCount);
	} catch(std::bad_alloc& e) {
		return ALLOCATION_ERROR;
	}
}

StatusType RemoveApplication(void *DS, int appID) {
	CHECK_NULL(DS);
	return ((iDroid*)DS)-> RemoveApplication(appID);
}

StatusType IncreaseDownloads(void *DS, int appID, int downloadIncrease) {
	CHECK_NULL(DS);
	try {
		return ((iDroid*)DS)-> IncreaseDownloads(appID, downloadIncrease);
	} catch(std::bad_alloc& e) {
		return ALLOCATION_ERROR;
	}
}

StatusType UpgradeApplication(void *DS, int appID) {
	CHECK_NULL(DS);
	try {
		return ((iDroid*)DS)-> UpgradeApplication(appID);
	} catch(std::bad_alloc& e) {
		return ALLOCATION_ERROR;
	}
}

StatusType GetTopApp(void *DS, int versionCode, int *appID) {
	CHECK_NULL(DS);
	return ((iDroid*)DS)-> GetTopApp(versionCode, appID);
}

StatusType GetAllAppsByDownloads(void *DS, int versionCode, int **apps, int *numOfApps) {
	CHECK_NULL(DS);
	return ((iDroid*)DS)-> GetAllAppsByDownloads(versionCode, apps, numOfApps);
}

StatusType UpdateDownloads(void *DS, int groupBase, int multiplyFactor) {
	CHECK_NULL(DS);
	try {
		return ((iDroid*)DS)-> UpdateDownloads(groupBase, multiplyFactor);
	} catch(std::bad_alloc& e) {
		return ALLOCATION_ERROR;
	}
}

void Quit(void** DS) {
	if ( !DS || !*DS ) return;
	delete (iDroid*)*DS;
	*DS = NULL;
}

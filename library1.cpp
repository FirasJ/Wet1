
#include "library1.h"
#include "iDroid.h"

void* Init() {
	iDroid* DS = new iDroid();
	return (void*)DS;
}

#define CHECK_NULL(ptr) if (!ptr) return INVALID_INPUT

StatusType AddVersion(void *DS, int versionCode) {
	CHECK_NULL(DS);
	return ((iDroid*)DS)-> AddVersion(versionCode);
}

StatusType AddApplication(void *DS, int appID, int versionCode, int downloadCount) {
	CHECK_NULL(DS);
	return ((iDroid*)DS)-> AddApplication(appID, versionCode, downloadCount);
}

StatusType RemoveApplication(void *DS, int appID) {
	CHECK_NULL(DS);
	return ((iDroid*)DS)-> RemoveApplication(appID);
}

StatusType IncreaseDownloads(void *DS, int appID, int downloadIncrease) {
	CHECK_NULL(DS);
	return ((iDroid*)DS)-> IncreaseDownloads(appID, downloadIncrease);
}

StatusType UpgradeApplication(void *DS, int appID) {
	CHECK_NULL(DS);
	return ((iDroid*)DS)-> UpgradeApplication(appID);
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
	return ((iDroid*)DS)-> UpdateDownloads(groupBase, multiplyFactor);
}

void Quit(void** DS) {
	if ( !DS || !*DS ) return;
	delete (iDroid*)*DS;
	*DS = NULL;
}

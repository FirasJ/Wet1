#ifndef IDROID_H_
#define IDROID_H_

#include "library1.h"
#include "list.h"
#include "tree.h"

/* 
 * Class DataByID :
 * This class represents an application  (ID/Version/Downloads) in our system.
 * The implementaion of operators < and > allow the use of this class
 * in our AVL tree in such a way that the nodes will be sorted according
 * to the ID of the application.
 * All the methods in this class are O(1).
 */
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

/* 
 * Class DataByDowns :
 * This class represents an application (ID/Version/Downloads) in our system.
 * The implementaion of operators < and > allow the use of this class
 * in our AVL tree in such a way that the nodes will be sorted according
 * to the number of downloads of the application as a primary rule,
 * and the ID as a secondary rule.
 * All the methods in this class are O(1).
 */
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

/* 
 * Class Version :
 * This class represents an OS version in our system.
 * It contains the version's ID and two AVL trees to the applications that
 * are supported by this version, One sorted by ID and the other by Downloads (ID as secondary) 
 * All the methods in this class are O(1).
 */
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
	
	/* Empty constructor :
	 * Description:   Initiates the data structure.
 	 * Input:         None.
	 * Output:        None.
 	 * Return Values: A new object of the data structure.
	 * Time Complexity: O(1).
 	 */
	iDroid();
	
	/* AddVersion :
	 * Description:   Adds a new version.
 	 * Input:         versionCode - The ID of the version to add.
 	 * Output:        None.
 	 * Return Values: INVALID_INPUT - if versionCode <= 0.
 	 *                FAILURE - If versionCode isn't bigger than that of the previous versions.
	 *                SUCCESS - Otherwise.
	 * Time Complexity: O(1).
 	 */
	StatusType AddVersion(int versionCode);
	
	/* AddApplication :
	 * Description:   Adds a new application to the system.
 	 * Input:         appID - ID of the application to add.
	 *                versionCode - The version that the application is compatible with.
	 *                downloadCount - The application's initial download count.
	 * Output:        None.
 	 * Return Values: INVALID_INPUT - if appID <=0, or if versionCode <=0, or if downloadCount < 0
	 *                FAILURE - If appID is already in the system, or versionCode isn't in the system.
 	 *                SUCCESS - Otherwise.
	 * Time Complexity: O(log(n)+k).
	 */
	StatusType AddApplication(int appID, int versionCode, int downloadCount);
	
	/* RemoveApplication :
	 * Description:   Removes an existing application.
 	 * Input:         appID - The ID of the application to remove.
 	 * Output:        None.
 	 * Return Values: INVALID_INPUT - if appID <= 0.
	 *                FAILURE - If appID isn't in the system.
	 *                SUCCESS - Otherwise.
	 * Time Complexity: O(log(n)+k).
 	 */
	StatusType RemoveApplication(int appID);

	/* IncreaseDownloads :	
	 * Description:   Increases the download count of an application.
 	 * Input:         appID - The ID of the application.
	 *		  downloadIncrease - The amount of downloads to add.
	 * Output:        None.
 	 * Return Values: INVALID_INPUT - if appID<=0, or if downloadIncrease<=0
	 *                FAILURE - If appID isn't in the system.
	 *                SUCCESS - Otherwise.
	 * Time Complexity: O(log(n)+k).
 	 */	
	StatusType IncreaseDownloads(int appID, int downloadIncrease);

	/* UpgradeApplication :	
	 * Description:   Upgrades an application to the following version
	 * Input:         appID - The ID of the application.
	 * Output:        None.
 	 * Return Values: INVALID_INPUT - if appID<=0.
 	 *                FAILURE - If appID isn't in the system, or there isn't a following version.
 	 *                SUCCESS - Otherwise.
	 * Time Complexity: O(log(n)+k).
	 */
	StatusType UpgradeApplication(int appID);

	/* GetTopApp :	
	 * Description:   Returns the most downloaded application in versionCode.
	 * 			If versionCode < 0, returns the most downloaded app in the entire system.
 	 * Input:         versionCode - The version that we'd like to get the data for.
	 * Output:        appID - A pointer to a variable that should be updated to the ID of the most downloaded app.
	 * Return Values: INVALID_INPUT - if appID == NULL or if versionCode == 0.
	 *                SUCCESS - Otherwise.
 	 * Time Complexity: O(k).
	 */
	StatusType GetTopApp(int versionCode, int *appID);

	/* GetAllAppsByDownloads :	
	 * Description:   Returns all the applications currently in versionCode sorted by their downloads.
 	 * 			If versionCode < 0, returns all the applications in the entire system sorted by their downloads.
 	 * Input:         versionCode - The version that we'd like to get the data for.
 	 * Output:        apps - A pointer to a to an array that you should update with the apps' IDs sorted by their downloads,
 	 *			in case two apps have same download count they should be sorted by their ID.
 	 *                numOfApps - A pointer to a variable that should be updated to the number of apps.
	 * Return Values: INVALID_INPUT - If any of the arguments is NULL or if versionCode == 0.
 	 *                SUCCESS - Otherwise.
	 * Time Complexity: O(n<version_code>+k).
 	 */
	StatusType GetAllAppsByDownloads(int versionCode, int **apps,
			int *numOfApps);

	/* UpdateDownloads :	
	 * Description:   Updates the download count of the applications where appID % groupBase == 0.
	 * 			For each matching app, multiplies its download count by multiplyFactor.
	 * Input:         groupBase - Represents a group of applications
 	 *		  multiplyFactor - The multiply factor.
	 * Output:        None.
 	 * Return Values: INVALID_INPUT - if groupBase < 1 or if multiplyFactor <=0
	 *                SUCCESS - Otherwise.
	 * Time Complexity: O(n+k).
 	 */
	StatusType UpdateDownloads(int groupBase, int multiplyFactor);
	
	/* Destructor :	
	 * Description:   deletes the database.
 	 * Input:         None.
	 * Output:        None.
 	 * Return Values: None.
	 * Time Complexity: O(n+k).
 	 */
	~iDroid();

private:

	List<Version> _versions;
	Tree<DataByID> _appsByIDtree;
	Tree<DataByDowns> _appsByDLtree;
	DataByDowns _max;

	/* getMax :	
	 * Description:   Gets the the application with the maximum number of downloads in a AVL tree.
 	 * Input:         tree - AVL tree of apps that is sorted by downloads (ID as secondary).
	 * Output:        None.
 	 * Return Values: The maximum application.
	 * Time Complexity: O(log(n)).
 	 */
	DataByDowns getMax(Tree<DataByDowns>& tree);
	
	/* getAllApps :	
	 * Description:   Puts all the apps (IDs) that are in an AVL tree in an array.
 	 * Input:         tree - AVL tree of apps that is sorted by downloads (ID as secondary).
	 * Output:        apps - The application IDs that we exracted from the tree.
	 * 		  numOfApps - The number of applications that were exracted.
 	 * Return Values: INVALID_INPUT - If any of the arguments is NULL or if versionCode == 0.
 	 *                SUCCESS - Otherwise.
	 * Time Complexity: O(log(n)).
 	 */
	StatusType getAllApps(const Tree<DataByDowns>& tree, int** apps,
			int* numOfApps);
};

#endif /* IDROID_H_ */

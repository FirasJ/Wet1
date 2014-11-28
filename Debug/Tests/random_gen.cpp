#include <iostream>
#include <random>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1,100000),dice(1,7);
	
	vector<int> vec;
	for (int i=0;i<500;i++) vec.push_back(dis(gen));
	vector<int> vv;
	for (int i : vec) for (int n=dice(gen);n;n--) vv.push_back(i);
	//for (int i:vv)cout<<i<<endl;
	random_shuffle(vv.begin(),vv.end());;
	set<int> s;
	for (int i:vv) {
		if (s.find(i)==s.end()) {
			s.insert(i);
			cout<<"insert "<<i<<endl;
		} else {
			s.erase(i);
			cout<<"remove "<<i<<endl;
		}
	}
	cerr<<"contains: ";
	for (int i:s) cerr<<i<<" ";
	cerr<<endl;
}

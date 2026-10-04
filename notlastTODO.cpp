#include "bits/stdc++.h"

using namespace std;

struct cow {
	string name;
	int milk;
};

cow cows[7];

int findCowIndex(string name) {
	int index = -1;
	for(int i=0; i<7; i++) {
		if(cows[i].name == name) {
			index = i;
			break;
		}
	}
	return index;
}

bool cmp(cow a, cow b) {
	return a.milk < b.milk;
}

int main() {
	freopen("notlast.in","r",stdin);
	freopen("notlast.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin>>n;
	cows[0] = {"Bessie", 0};
	cows[1] = {"Elsie", 0};
	cows[2] = {"Daisy", 0};
	cows[3] = {"Gertie", 0};
	cows[4] = {"Annabelle", 0};
	cows[5] = {"Maggie", 0};
	cows[6] = {"Henrietta", 0};
	
	string name;
	int milk;
	for(int i=0; i<n; i++) {
		cin>>name>>milk;
		// 更新对应奶牛的产奶量
		cows[findCowIndex(name)].milk += milk; 
	}
	
	// 按照产奶量从小到大排序
	sort(cows, cows + 7, cmp);
	
	// TODO
	for(int i=0;i<7;i++){
		if(cows[i].milk>cows[0].milk){
			if(i<6 && cows[i].milk == cows[i+1].milk){
				cout << "Tie";
			}else{
				cout << cows[i].name;
			}
			return 0;
		}
	}
	cout << "Tie";
}

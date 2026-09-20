#include "bits/stdc++.h"
using namespace std;

int add[200001];

priority_queue<int> pq1; // 大根堆  放排序后的前i-1个数 
priority_queue<int, vector<int>, greater<int> > pq2; // 小根堆 放排序后的i~n个数

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    int m, n;
	cin>>m>>n;
	for(int i=1; i<=m; i++) {
		cin>>add[i];
	}
	//cout << 1;
	int pos = 1;
	for(int i=1; i<=n; i++) {
		int q;
		cin>>q;
        for(int j=pos;j<=q;j++){
			//cout << add[j] << endl;
			pq1.push(add[j]);
			if(pq1.size() == i){ 
				int curr = pq1.top();
				pq1.pop();
				pq2.push(curr);
				//cout << curr << endl;
			}

		}
		cout << pq2.top() << endl;
		pos = q+1;

		int cur1 = pq2.top();
		pq2.pop();
		pq1.push(cur1);
	}
	
	return 0;
} 

#include "bits/stdc++.h"
using namespace std;

const int N = 2e5 + 5;
int h[N], a[N], t[N], p[N];

/*
calculates the ceiling of the division x / y 向上取整
floor向下取整
*/
int ceil(int x, int y) {
	return (x - 1) / y + 1;
}

int work() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> h[i];  // initail height
	
	for (int i = 1; i <= n; ++i)
		cin >> a[i];  // inches grows each day
	
	for (int i = 1; i <= n; ++i) {
		cin >> t[i];
		p[t[i]+1] = i; //找到t[i]对应的p
	}

	int ansL = 0, ansR = INT_MAX;

	for (int i = 1; i < n; ++i) {
		int x = p[i], y = p[i + 1];
		if(a[x]==a[y]){
			if(h[x]<=h[y]){
				return -1;
			}
		}else if(a[x]>a[y]){
			if(h[x]<=h[y]){
				ansL = max(ansL,ceil(h[y]-h[x]+1,a[x]-a[y]));
			}
		}else{ //a[x]<a[y]
			if(h[x]<=h[y]){
				return -1;
			}else{
				ansR = min(ansR,(h[x]-h[y]-1)/(a[y]-a[x]));
			}
		}
	}

	if (ansL > ansR)
		return -1;

	return ansL;
}

int main() {
	int T;
	cin >> T;

	while(T--){
		cout <<work() << endl;
	}

	return 0;
}

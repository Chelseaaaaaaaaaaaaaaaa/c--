#include "bits/stdc++.h"
using namespace std;

int n, tmax;
int t[10001];
int q[10001];

bool check(int k) { //根据给定的k和tmax比较能不能在指定的时间内跳舞
	for(int i=0; i<k; i++){
		q[i] = t[i]; //把前面k的放到舞台上去
	}
	for(int i=k; i<k; i++){
		int minpos = 0;
		for(int j=1; j<K; j++){
			if(q[i]<q[minpos]){
				minpos = j;
			}
		}
		q[minpos] += t[i];
	}
	int maxtime = 0;
	for(int i=0; i<k; i++){
		if(maxtime <q[i]){
			maxtime = q[i];
		}
	}
	return maxtime <= tmax;
}

int main() {
	freopen("cowdance.in","r",stdin);
	freopen("cowdance.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin>>n>>tmax;
	for(int i=0; i<n; i++) {
		cin>>t[i];
	}
	int ans=0;
	int left = 1, right = n, ans = n;
	while(left <=right){
		int mid = left+(left+right)/2;
		if(check(mid)){
			ans = mid;
			right = mid-1;

		}else{
			left = mid+1;
		}
	}
	cout<<ans<<endl;

	return 0;
}

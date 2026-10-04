#include "bits/stdc++.h"
using namespace std;

struct cow {
	int t, x, y;
};

cow c[251];
int n, t;
string s;
int state[101];  // 记录每头牛剩余的传染次数
bool candidates[101];
int minK=INT_MAX, maxK=INT_MIN;

bool cmp(const cow &a, const cow &b) {
	return a.t < b.t;
}

void shakeHands(int k);  // 函数声明

bool check();

int main()
{
	freopen("tracing.in", "r", stdin);
	freopen("tracing.out", "w", stdout);
	
	cin>>n>>t;
	cin>>s;
	for(int i=0; i<t; i++) {
		cin>>c[i].t>>c[i].x>>c[i].y;
		c[i].x--;  // 下标调整为从0开始 
		c[i].y--;
	}
	
	sort(c, c+t, cmp);
	
	for(int n0=0; n0<n; n0++) { // 枚举0号病人
		if(s[n0] == '0') {
			continue;
		}
		for(int k=0; k<=t; k++) { // 枚举k的值
		    memset(state, -1, sizeof(state));
			state[n0] = k;
			
			// 模拟握手
			shakeHands(k);

			// 检查是否匹配最终状态
            if (check()) {
                candidates[n0] = true;
                minK = min(minK, k);
                maxK = max(maxK, k);
            }
			 
		}		
	}
	
	int cnt = 0;
	for(int i=0; i<n; i++) {
		if(candidates[i]) {
			cnt++;
		}
	}

	cout<<cnt<<" "<<minK<<" ";

	if(maxK == t) {
		cout<<"Infinity"<<endl;
	} else {
		cout<<maxK<<endl;
	}

	return 0;
}

void shakeHands(int k) {
	for (int i = 0; i < t; i++)	{
		int x = c[i].x;
		int y = c[i].y;
		if(state[x]>0 && state[y]>0){
			state[x]--;
			state[y]--;
		} else if(state[x]>0){
			state[x]--;
			if(state[y]==-1){
				state[y]=k;
			}
		} else if(state[y]>0){
			if(state[x]==-1){
				state[x]=k;
			}
			state[y]--;
		}
	}
}

bool check() {
	for(int i=0;i<n;i++){
		char c = '0';
		if(state[i] != -1){
			c = '1';
		}

		if(s[i]!=c){
			return false;
		}
	}
	return true;
}
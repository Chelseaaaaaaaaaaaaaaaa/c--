///#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
vector<int> g[5001]; //graph
int outd[5001]; //outer degree
int ind[5001];//into degree
int f[50001]; //record the path of start to current pos
int MOD =  80112002;
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin >> x >> y;
        outd[x]++;
        ind[y]++;
        g[x].push_back(y);
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(ind[i]==0){
            q.push(i);//把每个点放到queue判断有多少个继续的点
            f[i]=1;
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto y: g[x]){
            f[y] = (f[x]+f[y]) % MOD;
            ind[y]--;
            if(ind[y]==0){ //没有点指向y了 删掉
                q.push(y);
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(outd[i]==0){
            ans = (ans+f[i])%MOD;
        }
    }
    cout<<ans<<endl;
    return 0;
}

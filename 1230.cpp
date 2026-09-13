///#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
int moo[100001], to[100001], inDegree[100001];
bool vis[100001];

int circle(int p) { //在环里寻找最小值
    vis[p] = true;
    int min1 = moo[p];
    while (!vis[to[p]]) {
        vis[to[p]] = true;
        min1 = min(min1, moo[to[p]]);
        p = to[p];
    }
    return min1;
}

void del(int i)  //删除i
{
    if (vis[i]) {
        return;
    }
    vis[i] = true;  //标记
    int v = to[i];
    inDegree[v]--;  // i的下一个人的入度减一
    if (inDegree[v] == 0) {
        del(v);
    }
}


int main(){
    int N;
    cin >> N;
    long long ans = 0;
    for(int i=1;i<=N;i++){
        cin >> to[i] >> moo[i]; 
        inDegree[to[i]]++;
        ans+=moo[i];
    }

    for(int i=1;i<=N;i++){
        if(inDegree[i]==0 && !vis[i]){
            del(i);
        }
    }

    for(int i=1;i<=N;i++){
        if(!vis[i]){
            ans -= circle(i);
        }
    }

    cout << ans;



    return 0;
}
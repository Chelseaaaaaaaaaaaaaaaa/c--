#include "bits/stdc++.h"

using namespace std;
int n,k;
int arr[201];
int cnt=0;

void dfs(int x){
    if(x==k){
        if(n>=arr[x-1]){
            cnt++;
        }
        return;
    }

    for(int i=arr[x-1];i<=n/(k-x+1);i++){
        arr[x]=i;
        n-=i;
        dfs(x+1);
        n+=i;
    }
}
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    arr[0]=1;
    dfs(1);
    cout << cnt;
    return 0;
}



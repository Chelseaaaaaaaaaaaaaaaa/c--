#include "bits/stdc++.h"

using namespace std;
int arr[11];
int ans[11];
bool vis[11];

int n;

void dfs(int x){
    if(x==n){
        for(int i=0;i<n;i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            ans[x] = arr[i];
            vis[i] = true;
            dfs(x+1);
            vis[i] = false;
        }
    }
    
}

int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    dfs(0);

    cout << "hello";
    return 0;
}



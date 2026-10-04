#include "bits/stdc++.h"

using namespace std;
int cnt[21][21];
int main(){
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int K,N;
    cin >> K >> N;
   for(int i=0;i<K;i++){
    int arr[N];
    for(int j=0;j<N;j++){
        cin >> arr[j];
    }
    for(int x=0;x<N;x++){
        for(int z=x+1;z<N;z++){
            cnt[arr[x]][arr[z]]++;
        }
    }
   }
   int ans = 0;
   for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
        if(cnt[i][j]==K){
            ans++;
        }
    }
   }
    cout << ans;
    return 0;
}

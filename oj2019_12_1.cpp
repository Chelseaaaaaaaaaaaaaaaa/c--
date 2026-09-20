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
            cnt[arr[z]][arr[x]]--;
        }
    }
   }
   int ans = 0;
   for(int x=1;x<=N;x++){
    for(int y=1;y<=N;y++){
        if(cnt[x][y]==0){
            ans++;
        }
    }
   }
    cout << ans-N;
    return 0;
}

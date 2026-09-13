#include "bits/stdc++.h"
using namespace std;

int N, B, F[251], S[251], D[251], answer = INT_MAX;
bool vis[251][251];  // set of (location, boot) states we can reach

// recursively search through all reachable states
void dfs(int tileId, int bootId)  // 第tileId个tile, 目前穿着第bootId双靴子
{
   if(vis[tileId][bootId]){
    return;
   }

   vis[tileId][bootId]=true;

   if(tileId==N){
    answer = min(answer,bootId-1);
    return;
   }

    //Try all the steps forward
   for(int i=1;i<=D[bootId];i++){
    if(tileId+i<=N && F[tileId+i]<=S[bootId]){
        dfs(tileId+i,bootId);
    }
   }

   //Try all the boots
   for(int i=bootId+1;i<=B;i++){
    if(F[tileId]<=S[i]){
        dfs(tileId,i);
    }
   }
}

int main() {
       freopen("snowboots.in", "r", stdin);
       freopen("snowboots.out", "w", stdout);

    cin >> N >> B;
    for (int i = 1; i <= N; i++) {
        cin >> F[i];
    }
    for (int i = 1; i <= B; i++){
        cin >> S[i] >> D[i];
    } 

    dfs(1, 1);
    cout << answer << endl;

    return 0;
}

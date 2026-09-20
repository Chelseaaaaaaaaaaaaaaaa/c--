#include "bits/stdc++.h"
//Bessie starts at field 1, costs B per edge
//Elsie starts at field 2, costs E per edge
//Together they can piggyback from some meeting point i to the field N costs P per edge
//Total cost = B \times dis(1,i) + E \times dis(2,i) + P \times (i, N)
using namespace std;
const int MAXN = 40005;
vector<int> g[40001];
int disB[MAXN], disE[MAXN],disN[MAXN];
int B,E,P,N,M,ans = INT_MAX;
bool vis[MAXN];
void bfs(int start, int dis[]){
    queue<int> q;
    bool vis[MAXN] = {}; //刷新一下 因为会多次运用
    q.push(start);
    vis[start] = true;
    dis[start] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto &to: g[curr]){ //与当前的点所有相关的
            if(vis[to]){
                continue;
            }
            q.push(to);
            vis[to] = true;
            dis[to] = dis[curr]+1; //从上一个点过来加一
        }
    }
}
int main(){
    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);
    cin >> B >> E >> P >> N >> M;
    for(int i=0;i<M;i++){
        int from, to;
        cin >> from >> to;
        g[from].push_back(to); //graph的模版
        g[to].push_back(from);
    }
    bfs(1,disB);
    bfs(2,disE);
    bfs(N,disN);
    for(int i=1;i<=N;i++){
        ans = min(ans,disB[i]*B + disE[i]*E + disN[i]*P);
    }

    cout << ans << endl;
    return 0;
}
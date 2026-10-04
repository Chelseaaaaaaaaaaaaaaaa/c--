#include "bits/stdc++.h"

using namespace std;
struct edge{
    int to, w;
}
int bfs(int k, int startPoint){
    queue<int>
}
int n,q;
vector<edge> g[5001];//有权重才需要加edge
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    cin >> n >> q;
    int x,y,r;
    for(int i=1;i<n;i++){ //n-1 edges, x,y都是从1开始的
        cin >> x >> y >> r;
        //无向图双向加边
        g[x].push_back({y,r});
        g[y].push_back({x,r});

    }
    int k,v;
    for(int i=1;i<=q;i++){
        cin >> k >> v;
        cout << bfs(k,v) << endl;
    }
    cout << "hello"; 
    return 0;
}
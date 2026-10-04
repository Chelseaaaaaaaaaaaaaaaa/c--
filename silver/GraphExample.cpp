#include "bits/stdc++.h"
//goal: to find all videos reachable that have the minimum weight of k
using namespace std;
struct edge{
    int to,w; // w=weight7
};
vector<edge> g[5001]; // store the tree
int bfs(int k, int startpoint){ // how many we can reach from the start point
    queue<int> q;
    q.push(startpoint);
    bool vis[5001] = {};
    vis[startpoint] = true;
    int cnt = 0;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        
        for(auto &e: g[current]){
            if(!vis[e.to]&&e.w >=k){ //all the weight  should be bigger than k, because the smaller weight is the one that restrict the weight (bottle neck), if I encounter a weight smaller tha k, then it makes the entire relevacne smaller than k
                q.push(e.to); //add to the end
                vis[e.to]=true;
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<n;i++){
        int p,q,r;
        cin >> p >> q >> r;
        g[p].push_back({q,r});
        g[q].push_back({p,r});
    }
    int k,v;
    for(int i=1;i<=q;i++){
        cin >> k >> v;
        cout << bfs(k,v) << endl;
    }
    return 0;
}
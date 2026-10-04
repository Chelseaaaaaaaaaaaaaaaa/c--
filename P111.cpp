#include "bits/stdc++.h"

using namespace std;
struct road{
    int x,y,t;
};
int f[1001];
road r[100001];
int cnt = 0;

bool comp(const road &a, const road &b){
    return a.t<=b.t;
}

int find(int v) {  // 找root
    if(f[v] == v) return v;
    return f[v] = find(f[v]);  // 路径压缩
}
void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u!=v){
        f[v]=u;
        cnt++;
    }
}

int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,M;
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int x,y,t;
        cin >> r[i].x >> r[i].y >> r[i].t;
    }
    sort(r,r+M,comp);
    for(int i=1;i<=N;i++){
        f[i] = i;
    }

    for(int i=0;i<M;i++){
        merge(r[i].x,r[i].y);
        if(cnt==N-1){
            cout << r[i].t;
            return 0;
        } 
    }

    cout << -1;
    return 0;
}

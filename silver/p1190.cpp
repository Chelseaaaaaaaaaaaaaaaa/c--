#include "bits/stdc++.h"

using namespace std;
priority_queue<int, vector<int>, greater<int> > pq;
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int w;
        cin >> w;
        pq.push(w);
    }
    for(int i=m;i<n;i++){
        int minn = pq.top();
        pq.pop();
        int w;
        cin >> w;
        pq.push(minn+w);
    }
    int maxn = 0;
    while(pq.size()>0){
        maxn = pq.top();
        pq.pop();
    }
    cout << maxn;
    return 0;
}



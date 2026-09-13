#include "bits/stdc++.h"
using namespace std;

int to[100001];
int indegree[100001];
bool vis[100001];
int ans[100001];

void del(int i) {
    if(vis[i]){
        return;
    }

    vis[i] = true;
    int v = to[i];
    indegree[v]--;
    if(indegree[v]==0){
        del(v);
    }
}

void circle(int p) {
    vis[p] = true;
    vector<int>points;
    points.push_back(p);
    while(!vis[to[p]]){
        vis[to[p]] = true;
        points.push_back(to[p]);
        p = to[p];
    }

    for(int i:points){
        ans[i] = points.size();
    }
}

int calcTail(int i) {
    if(ans[i]>0){
        return ans[i];
    }

    ans[i] = calcTail(to[i])+1;
    return ans[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> to[i];
        indegree[to[i]]++;
    }

    // 删除环外的点
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0 && !vis[i]) {
            del(i);
        }
    }

    // 计算环上的点
    for (int i = 1; i <= n; i++) {
        if (indegree[i] > 0 && ans[i] == 0) {
            circle(i);
        }
    }

    // 计算环外的点
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0 && ans[i] == 0) {
            calcTail(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
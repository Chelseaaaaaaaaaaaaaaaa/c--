#include <bits/stdc++.h>
using namespace std;

vector<int> g[200010];

long long num[200010];
vector<pair<int, long long>> dag[200010];
long long avg = 0;
int ans = 0;
int indegree[200010];

void dfs(int cur, int fa) {
    for (int to : g[cur]) {
        if (to != fa) dfs(to, cur);
    }
    if (num[cur] != avg) {
        ans++;
        if (num[cur] > avg) {
            dag[cur].push_back({fa, num[cur] - avg});
            num[fa] += num[cur] - avg;
            indegree[fa]++;
        } else {   
            dag[fa].push_back({cur, avg - num[cur]});
            num[fa] -= avg - num[cur];
            indegree[cur]++;
        }
    }
}

queue<int> q;

/*
首先dfs找到每条边搬多少，然后有个细节是如果直接做可能出现负数，
所以要再用一个bfs，先从没有入度的点开始走，避免这种情况
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        avg += num[i];
    }

    avg /= n;
    for (int i = 1; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2); // 原始图
        g[t2].push_back(t1);
    }

    dfs(1, 0);  
    cout << ans << endl;

    // topological sort
    for (int i = 1; i <= n; i++)
        if (indegree[i] == 0) q.push(i);

    while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (auto e : dag[a]) {
            cout << a << " " << e.first << " " <<  e.second << '\n';
            indegree[e.first]--;
            if (indegree[e.first] == 0) q.push(e.first);
		}
    }
}

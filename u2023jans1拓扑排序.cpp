#include "bits/stdc++.h"
using namespace std;

int g[130];  // 字母转换列表
int indegree[130];       // 入度
int ind2[130];      // 入度备份，因为拓扑排序会改变indegree[i]
bool vis[130];     // 标记是否在环内
int ans;

bool toposort() {
    queue<int> q;
    for (int i = 1; i < 130; i++) {
        if(g[i] == 0) {
            continue;
        }
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    bool allincycle = true; //52字母都在环上 无法中转
    while (!q.empty()) {  // 拓扑找环
        int t = q.front();
        q.pop();
        vis[t] = true;
        allincycle = false; //如果topo函数能删掉一个 那么意味着52个字母不在函数上
        indegree[g[t]]--;
        if (indegree[g[t]] == 0 && g[g[t]] != 0) q.push(g[t]); //g[g[t]]指向别人
    }

    return allincycle;
}

int findcycles() {
    int cyclecnt = 0;
    for (int i = 1; i < 130; i++) {
        if(g[i] == 0) {
            continue;
        }
        if (!vis[i]) {
            int j = i; //起点存到j
            int len = 0;
            bool onlycycle = true;
            while (vis[j] == 0 && g[j] != 0) {
                vis[j] = 1;
                j = g[j];
                len++;//环的长度
                if (ind2[j] > 1) {
                    onlycycle = false; //除了环上的点指向他还有别的点指向他
                }
            }
            if (len >= 2 && onlycycle) {
                cyclecnt++; // 如果出现环(ab变ba或者abc变bca这样）并且没有其他边进入，就额外+1,  比如ABC->BAA，不需要+1
            }
        }
    }
    return cyclecnt;
}    

void solve() {
    memset(g, 0, sizeof(g)); //清空函数，sizeof(g)表示g里面有多少个bite设置成0
    memset(indegree, 0, sizeof(indegree));
    memset(ind2, 0, sizeof(ind2));
    memset(vis, 0, sizeof(vis));
    ans = 0;

    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++) {
        if(g[s1[i]] == 0) {
            g[s1[i]] = s2[i];//已经转换好了
        } else if(g[s1[i]] != s2[i]) {// 排除一个字符变成多个（aa变ab）的情况
            cout << "-1" << endl; 
            return;
        }
    }

    for (int i = 1; i < 130; i++) {
        if (g[i] != 0) {
            indegree[g[i]]++;
            ind2[g[i]]++;
        }
    }
    //不考虑环的情况下转换多少次
    int sum = 0;  // s1中总共出现的字母种类
    for (int i = 1; i < 130; i++) {
        if(g[i] == 0) {
            continue;
        }
        sum++;//一共出现多少个字母
        if (g[i] != i) { // 统计需要反转的字母个数
            ans++;
        }
    }
    
    // 拓扑找环，返回是否所有字母都在环内
    bool allincycle = toposort(); 
    // 如果出现环(ab变ba或者abc变bca这样）并且没有其他边进入，就额外+1,  比如ABC->BAA，不需要+1
    int cyclecnt = findcycles(); 

    if (allincycle && sum == 52 && cyclecnt > 0) {
        // 有环但没有中转字母的(52个字母全部在环上)，则无解，就输出-1
        cout << "-1" << endl;
        return;
    }
    ans += cyclecnt;
    cout << ans << endl;
}

/*
首先排除一个字符变成多个（aa变ab）的情况，
然后统计需要反转的字母个数，
如果出现环(ab变ba或者abc变bca这样）并且没有其他边进入，就额外+1，否则不加，比如ABC->BAA，不需要+1
最后有环但没有中转字母的(52个字母全部在环上)，则无解，就输出-1
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }

    return 0;
}

/*
abcdefhg
badefegh
10
*/

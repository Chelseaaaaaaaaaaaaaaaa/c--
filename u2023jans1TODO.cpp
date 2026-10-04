#include "bits/stdc++.h"
using namespace std;

int g[130];  // 字母转换列表
int indegree[130];       // 入度
int ind2[130];      // 入度备份，因为拓扑排序会改变indegree[i]
bool vis[130];     // 标记是否在环内
int ans;

void init() {
    memset(g, 0, sizeof(g));
    memset(indegree, 0, sizeof(indegree));
    memset(ind2, 0, sizeof(ind2));
    memset(vis, 0, sizeof(vis));
    ans = 0;
}

bool toposort() {
    queue<int> q;
    for(int i=1;i<130;i++){
        if(g[i]==0){
            continue;
        }
        if(indegree[i]==0){
            q.push(i);
        }

    }

    bool allincircle = true;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        vis[t] = true;
        allincircle = false;
        indegree[g[t]]--;
        if(indegree[g[t]]==0 && g[g[t]]!=0 ){ //g[g[t]]指向别人
            q.push(g[t]);
        }
    }

    return allincircle;
}

int findcycles() {
    int cyclecnt = 0;
    for(int i=1;i<130;i++){
        if(g[i]==0){
            continue;
        }

        if(!vis[i]){
            int j=i;
            int len = 0;
            bool onlycycle = true;
            while(!vis[j]&&g[j] != 0){
                vis[j] = 1;
                j = g[j];
                len++;
                if(ind2[j]>=2){
                    onlycycle = false;
                }

            }
            if(len>=2 && onlycycle){
                cyclecnt++;
            }
        }
    }
    return cyclecnt;
}

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++) {
        if(g[s1[i]]==0){
            g[s1[i]] = s2[i];
        }else if(g[s1[i]]!=s2[i]){
            cout << -1 << endl;
            return;
        }
    }

    for (int i = 1; i < 150; i++) {
        if (g[i] != 0) {
            indegree[g[i]]++;
            ind2[g[i]]++;
        }
    }

    int sum = 0;  // s1中总共出现的字母个数
    for (int i = 1; i < 150; i++) {
        if(g[i] == 0) {
            continue;
        }
        sum++;
        if (g[i] != i) {
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
        init();
        solve();
    }

    return 0;
}

/*
abcdefhg
badefegh
10
*/

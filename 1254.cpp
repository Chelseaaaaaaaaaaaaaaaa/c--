#include "bits/stdc++.h"

using namespace std;
int barn[200001];
vector<int> g[200010];
vector<pair<int, long long>> dag[200010]; //有向无环图
int indegree[200010];
int ans = 0;
long long avg = 0;
int N = 0;

void dfs(int start, int fa){
    for(int to:g[start]){
        if(to != fa){
            dfs(to, start);
        }
    }
    if(barn[start] != avg){
        ans++;
        if(barn[start] > avg){
           dag[start].push_back({fa,barn[start]-avg});
           barn[fa] += barn[start] - avg;
           indegree[fa]++;
        }else{
            dag[fa].push_back({start,avg-barn[start]});
            barn[fa] -= avg-barn[start];
            indegree[start]++;
        }
    }

    queue<int> q;
    for(int i=0;i<N;i++){
        if(indegree[N]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int a = q.front();
        q.pop();
        for(auto e:dag[a]){
            cout << a << " " << e.first << " " << e.second << endl;
            indegree[e.first]--;
            if(indegree[e.first]==0){
                q.push(e.first);
            }
        }
    }


}
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> barn[i];
        avg += barn[i]; 

    }
    avg = avg/N;

    for(int i=1; i<N; i++){
        int t1,t2;
        cin >> t1 >> t2;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    dfs(1,0);

    cout << ans << endl;



    cout << "hello";
    return 0;
}



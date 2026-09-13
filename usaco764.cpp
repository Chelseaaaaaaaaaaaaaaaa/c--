///#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
int to[100001];
int indegree[100001];

int main(){
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> to[i];
        indegree[to[i]]++;
    }

    queue<int> q;
    int cnt = 0;
    for(int i=1;i<=N;i++){
        if(indegree[i]==0){
            q.push(i);
            cnt++;
        }
    }
    while(!q.empty()){
        int t=q.front();
        q.pop();
        int v=to[t];
        indegree[v]--;
        if(indegree[v]==0){
            q.push(v);
            cnt++;
        }
    }
    cout << N-cnt << endl;
    
}
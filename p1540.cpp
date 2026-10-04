#include "bits/stdc++.h"

using namespace std;
queue<int> q;
bool vis[1001];
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int M,N;
    cin >> M >> N;
    int cnt = 0;
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        if(!vis[num]){
            if(q.size() <M){
                q.push(num);
                vis[num] = true;
                
            }else{
                vis[q.front()] = false;
                q.pop();
                q.push(num);
                vis[num] = true;
            }
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
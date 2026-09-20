#include "bits/stdc++.h"

using namespace std;
queue<int>q;
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            q.push(q.front());
            q.pop(); 
        }
        cout << q.front() << ' ';
        q.pop();
    }
    return 0;
}
#include "bits/stdc++.h"

using namespace std;
struct cow{
    int w, a;
};

bool comp(const cow &a, const cow &b){
    return a.w > b.w;
}

cow arr[200001];
queue<cow> q;

int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        cin >> arr[i].w >> arr[i].a;
    }
    sort(arr, arr+n, comp);
    long long ans = 0;
    q.push({INT_MAX,m});
    for(int i=0;i<n;i++){
        int cnt = 0; 
        while(!q.empty()){
            auto &p = q.front(); 
            if(p.w-arr[i].w < k){
                break;
            }
            int delta = min(p.a, arr[i].a);
            p.a -= delta;
            arr[i].a -= delta;
            cnt += delta;

            if(!p.a){
                q.pop();
            }

            if(!arr[i].a){
                break;
            }

            
        }
        ans += cnt;
        q.push({arr[i].w, cnt});
    }
    
    cout << ans;
    return 0;
}



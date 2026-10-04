#include "bits/stdc++.h"

using namespace std;

set<int> s;
int arr[100010];
int interval[100010];
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,t;
    cin >> n >> k;

    for(int i=1; i<=n;i++){
        cin >> t;
        s.insert((t+11)/12);
    }

    int cnt = 0;
    for(auto &t:s){
        arr[cnt] = t;
        cnt++;
    }

    interval[0] = arr[0]-1;
    for(int i=1; i<cnt; i++){
        interval[i] = arr[i] - arr[i-1] - 1; 
    }

    int saved = 0;
    sort(interval, interval + cnt, greater<int> ());
    for(int i=0; i<k-1;i++){
        saved += interval[i];
    }

    cout << (arr[cnt-1] - saved)*12 << endl; // 最大的周期减去 省去的周期

    return 0;
}



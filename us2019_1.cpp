#include "bits/stdc++.h"

using namespace std;
int main(){
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int N;
    int a[101];
    int b[101];
    int g[101];
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> a[i] >> b[i] >> g[i];
    }
    int big = 0;
    for(int i=1;i<=3;i++){
        int cnt =0;
        bool shells[4] = {};
        shells[i] = true;
        for(int i=0; i<N;i++){
            swap(shells[a[i]],shells[b[i]]);
            if(shells[g[i]]){
                cnt++;
            }
        }
        big = max(cnt,big);
    }
    cout << big;
    return 0;
}
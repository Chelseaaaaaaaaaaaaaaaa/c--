#include "bits/stdc++.h"

using namespace std;
int cow[501][501];
int all[501][501];
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int N,K,Q;
    cin >> N >> K >> Q;
    int ans = INT_MIN;
    for(int i=0;i<Q;i++){
        int r,c,v;
        cin >> r >> c >> v;
        int maxa = max(1,r-K+1);
        int maxb = max(1,c-K+1);
        for(int a = maxa;a<=r;a++){
            for(int b=maxb;b<=c;b++){
                int dif = v-cow[r][c];
                all[a][b] += dif;
                ans = max(ans,all[a][b]);
            }
        }
        cow[r][c] = v;
        cout << ans << endl;

    }
}



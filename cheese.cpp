#include "bits/stdc++.h"

using namespace std;
int xy[1001][1001];
int xz[1001][1001];
int yz[1001][1001];
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int N,Q;
    cin >> N >> Q;
    int ans = 0;
    for(int i=0;i<Q;i++){
        int x,y,z;
        cin >> x >> y >> z;
        xy[x][y]++;
        xz[x][z]++;
        yz[y][z]++;
        if(xy[x][y]==N){
            ans++;
        }if(xz[x][z]==N){
            ans++;
        }if(yz[y][z]==N){
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}



#include "bits/stdc++.h"

using namespace std;
int cow[1010][1010];
int cnt[1010][1010];
int ans;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
void add(const int &a,const int &b){
    cow[a][b] = 1;
    if(cnt[a][b] == 3){
        ans++;
    }
    for(int k=0;k<4;k++){
        int newi = a + dir[k][0];
        int newj = b + dir[k][1];
        cnt[newi][newj]++;
        if(cow[newi][newj]){
            if(cnt[newi][newj]==3){
                ans++;
            }
            if(cnt[newi][newj]==4){
                ans--;
            }
        }
    }
    

}
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int x,y;
        cin >> x >> y;
        x++,y++;
        add(x,y);
        cout << ans << endl;
    }
    return 0;
}
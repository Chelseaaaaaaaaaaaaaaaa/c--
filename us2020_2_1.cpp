#include "bits/stdc++.h"

using namespace std;
int x[101];
int y[101];
int main(){
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> x[i] >> y[i];
    }
    int ans = 0;

    for(int i=1;i<=N;i++){
        int lenx = 0;
        int leny = 0;
        int maxx=0;
        int maxy = 0;
        for(int j=1;j<=N;j++){
            if(x[i]==x[j]){
                leny = abs(y[j]-y[i]);
                maxy = max(maxy,leny);
            } 
            if(y[i]==y[j]){
                lenx = abs(x[i]-x[j]);
                maxx = max(lenx,maxx);
            }
        }
        ans = max(ans,leny*lenx);
    }
    cout << ans;
    return 0;
}
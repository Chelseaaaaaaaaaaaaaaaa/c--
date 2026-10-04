#include "bits/stdc++.h"

using namespace std;
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int N;
    cin >> N;
    string cow;
    cin >> cow;
    int ans=0;
    for(int i=0;i<N;i++){
        int cntH=0,cntG=0;
        for(int j=i;j<N;j++){
            if(cow[j]=='G'){
                cntG++;
            }
            if(cow[j]=='H'){
                cntH++;
            }
            if(j-i+1>=3 && (cntG==1 || cntH == 1)){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}



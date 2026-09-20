#include "bits/stdc++.h"

using namespace std;
int main(){
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int N,a,b;
    cin >> N;
    int cntA = 0;
    int cntB = 0;
    for(int i=0;i<N;i++){
        cin >> a >> b;
        if(a-b==-1||a-b==2){
            cntA++;
        }
        if(a-b==1||a-b == -2 ){
            cntB++;
        }
    }
    cout << max(cntA,cntB);
}
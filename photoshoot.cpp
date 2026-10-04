#include "bits/stdc++.h"

using namespace std;
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int N;
    cin >> N;
    string cow;
    cin >> cow;
    int cnt=0;
    string pre;
    for(int i=0;i<N-1;i=i+2){
        if(cow[i]==cow[i+1]){
            continue;
        }if(cow[i]=='G' && cow[i+1]=='H'){
            if(pre != "GH"){
                cnt++;
            }
            pre = "GH";
        }if(cow[i]=='H' && cow[i+1]=='G'){
            if(pre != "HG"){
                cnt++;
            }
            pre = "HG";
        }
    }
    if(pre == "HG"){
        cnt--;
    }
    cout << cnt;
    return 0;
}



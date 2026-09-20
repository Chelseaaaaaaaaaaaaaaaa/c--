///#include <bits/stdc++.h>
#include "macstdc++.h"
using namespace std;
int cnt[1001];
int main(){
    int N,a;
    cin >> N;
    int sum = 0;
    for(int i=0; i<N;i++){
        cin >> a;
        cnt[a] ++;
        if(cnt[a]==1){
            sum++;
        }
    }
    cout<<sum<<endl;
    for(int i=1;i<=1000;i++){
        if(cnt[i]>0){
            cout << i <<" ";
        }
    }



}



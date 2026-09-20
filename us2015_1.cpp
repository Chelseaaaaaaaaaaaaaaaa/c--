#include "bits/stdc++.h"
using namespace std;
int paint[101];
int main(){
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    for(int i=a;i<b;i++){
        paint[i]++;
    }
    for(int i=c; i<
        d;i++){
        paint[i]++;
    }
    int cnt = 0;
    for(int i=0;i<=100;i++){
        if(paint[i]>0){
            cnt++;
        }
    }
    cout << cnt;
}



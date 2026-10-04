#include "bits/stdc++.h"

using namespace std;

void power(int a){
    int value = 1; 
    int t = 0;
    while(value*2<=a){
        value *= 2;
        t++;
    }
    a -= value;
    if(t == 0 || t == 2){
        cout << "2(" << t << ")";
    }else if(t==1){
        cout << 2;
    }else{
        cout << "2(";
        power(t);
        cout << ")";
    }

    if(a>0){
        cout << "+";
        power(a);
    }
  
}
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    power(n);
    return 0;
}



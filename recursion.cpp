#include "bits/stdc++.h"

using namespace std;

int f[100];


int fibonacci(int n){
    if(f[n] > 0){
        return f[n];
    }
    if(n==1 || n==2){
        return 1;
    }else{
        f[n] = fibonacci(n-1)+fibonacci(n-2);
        return f[n];
    }
    
}


int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fibonacci(6);
    return 0;
}



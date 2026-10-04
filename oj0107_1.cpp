#include "bits/stdc++.h"
using namespace std;
int main(){
    int cnt = 0;
    string n;
    getline(cin,n);
    for(char ch:n){
        if(ch >= '0'&& ch <='9'){
            cnt++;
        }
    }
    
    
    cout << cnt;
}


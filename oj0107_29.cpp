#include <bits/stdc++.h>
///#include "macstdc++.h"
using namespace std;
int main(){
    string n;
    cin >> n;
    int sum=0;
    int cnt = 0;
    for(int i=0;i<n.length()-1;i++){
        if(n[i] != '-'){
            cnt++;
            sum += (n[i] -'0') * cnt;

        }
    }
    char code = sum%11 + '0';
    if(sum %11 == 10){
        code = 'X';
        
    }
    if(code == n[n.length()-1]){
        cout << "Right";
    }else{
        n[n.length()-1] = code;
        cout << n;
    }
    
}



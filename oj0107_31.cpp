#include <bits/stdc++.h>
///#include "macstdc++.h"
using namespace std;
int main(){
    string n; 
    cin >> n;
    int cnt = 1;
    for(int i=1; i<n.length();i++){
        if(n[i]==n[i-1]){
            cnt++;
        }else{
            cout << cnt << n[i-1];
            cnt = 1;
        }
    }
    cout << cnt << n[n.length()-1];
}



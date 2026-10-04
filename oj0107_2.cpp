///#include <bits/stdc++.h>
#include "macstdc++.h"
using namespace std;
int main(){
    string n;
    cin >> n;
    int cnt[26];
    for(int i=0; i<n.length();i++){
        cnt[n.charAt(i)-"a"]++;
    }
    for(int i=0;i<n.length();i++){
        if(cnt[n.charAt(i)-"a"]==1){
            cout << n.charAt(i);
            return;
        }
    }
}



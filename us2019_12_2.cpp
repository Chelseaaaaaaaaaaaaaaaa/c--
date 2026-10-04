#include "bits/stdc++.h"

using namespace std;
int checklen(int a, int b,string c){
    int len = 0;
    while(c[a+len]==c[b+len]){
        len++;
    }
    return len;
}
int main(){
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    int N;
    cin >> N;
    string s;
    cin >> s;
    int large=0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int len = checklen(i,j,s);
            large = max(large,len); 
        }
    }
    cout << large+1;
    return 0;
}
#include "bits/stdc++.h"

using namespace std;
char guess[3][3];
char ans[3][3];
int cntg[26];
int cnta[26];
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> guess[i][j];
            cntg[guess[i][j]-'A']++;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> ans[i][j];
            cnta[ans[i][j]-'A']++;
        }
    }
    int green = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(guess[i][j]==ans[i][j]){
                green++;
            }
        }
    }
    int yellow = 0;
    for(int i=0;i<26;i++){
        yellow += min(cntg[i],cnta[i]);
    }
    cout << green << endl << yellow-green;
    return 0;
}
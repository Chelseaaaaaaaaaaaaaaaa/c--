#include "bits/stdc++.h"

using namespace std;
string s[101];
string p[101];
int main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int N,M;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> s[i];
    }
    for(int i=0;i<N;i++){
        cin >> p[i];
    }
    int cnt = 0;
    for(int col=0;col<M;col++){
        bool A = false;
        bool C = false;
        bool G = false;
        bool T = false;
        for(int row = 0; row<N;row++){
            if(s[row][col]== 'A'){
                A = true;
            }
            if(s[row][col]== 'C'){
                C = true;
            }
            if(s[row][col]== 'G'){
                G = true;
            }
            if(s[row][col]== 'T'){
                T = true;
            }
        }
        bool conflict = false;
        for(int row=0;row<N;row++){
            if(p[row][col]=='A'&& A){
                conflict = true;
                break;
            }
            if(p[row][col]=='G'&& G){
                conflict = true;
                break;
            }
            if(p[row][col]=='C'&& C){
                conflict = true;
                break;
            }
            if(p[row][col]=='T'&& T){
                conflict = true;
                break;
            }  
        }
        if(!conflict){
            cnt++;
        }
    }
    cout << cnt;
    return 0;

}
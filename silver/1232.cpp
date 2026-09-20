#include "bits/stdc++.h"

using namespace std;
int l[200001];
int r[200001];
int prefixc[200001];
int prefixo[200001];
int prefixw[200001];
void prefixSum(string s1){
    for(int i=0;i<s1.length();i++){
        prefixc[i+1] = prefixc[i];
        prefixo[i+1] = prefixo[i];
        prefixw[i+1] = prefixw[i];
        if(s1[i] == 'C'){
            prefixc[i+1]++;
        }else if(s1[i]=='O'){
            prefixo[i+1]++;
        }else if(s1[i]=='W'){
            prefixw[i+1]++;
        }
    }
}
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    string s;
    cin >> s;
    prefixSum(s);
    int Q;
    cin >> Q;
    for(int i=0;i<Q;i++){
        int l,r;
        cin >> l >> r;
        int cntc = prefixc[r]-prefixc[l-1];
        int cnto = prefixo[r]-prefixo[l-1];
        int cntw = prefixw[r]-prefixw[l-1];
        //cout << cntc << cnto << cntw;
        if(cntc%2==0&&cnto%2==1&&cntw%2==1){
            cout << 'Y';
        }else if(cntc%2==1&&cnto%2==0&&cntw%2==0){
            cout << 'Y';
        }else{
            cout << 'N';
        }
    }
    
    
    return 0;
}



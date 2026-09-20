#include "bits/stdc++.h"

using namespace std;
int ord[101];
int id[101];
int temp[101];
int main(){
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int N,t;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> t;
        ord[t]=i;
    }
    for(int i=1;i<=N;i++){
        cin >> id[i];
    }
    for(int i=0;i<3;i++){
        for(int j=1;j<=N;j++){
            temp[ord[j]] = id[j]; 
        }
        for(int j=1;j<=N;j++){
            id[j] = temp[j];
        }
    }

    for(int i=1;i<=N;i++){
        cout << id[i] << endl;
    }


    return 0;
}
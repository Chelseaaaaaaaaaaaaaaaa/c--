#include "bits/stdc++.h"

using namespace std;
char arr[11][11];
int main(){
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    int M,N,K;
    cin >> M >> N >> K;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<K;j++){
            for(int a=0;a<N;a++){
                for(int b=0;b<K;b++){
                    cout << arr[i][a];
                }
            }
            cout << endl;
        }
    }
    return 0;
}



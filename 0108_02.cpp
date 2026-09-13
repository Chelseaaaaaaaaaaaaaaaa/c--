#include <bits/stdc++.h>
///include "macstdc++.h"
using namespace std;

int main(){
    int N,I,J;
    cin >> N >> I >> J;
    for(int i=1; i<=N;i++){
        cout << "(" << I << "," << i << ") ";
    }
    cout << endl;
    for(int i=1;i<=N;i++){
        cout << "(" << i << "," << J << ") ";
    }
    cout << endl;
    int dif = I-J;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i-j == dif){
                cout << "(" << i << "," << j << ") ";
            }
        }
    }
    cout << endl;
    int sum = I+J;
    for(int j=1;j<=N;j++){
        for(int i=N;i>=1;i--){
            if(i+j == sum){
                cout << "(" << i << "," << j << ") ";
            }
        }
    }
}
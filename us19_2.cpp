#include "bits/stdc++.h"

using namespace std;
int arr[101];
int main(){
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    int N;
    cin >> N;
    for(int i=0; i<N;i++){
        int order;
        cin >> order;
        arr[i] = order;
    }
    for(int i=N-1;i>=0;i--){
        if(arr[i-1]>arr[i]){
            cout << i;
            return 0;
        }
    }
    cout << 0;

    
}
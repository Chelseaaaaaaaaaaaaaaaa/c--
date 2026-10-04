#include "bits/stdc++.h"

using namespace std;
int arr[101];
int arr1[101];
bool comp(const int&a, const int&b){
    return a<b;
}
int main(){
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
        arr1[i]=arr[i];
    }
    sort(arr,arr+N,comp);
    int cnt=0;
    for(int i=0;i<N;i++){
        if(arr1[i]!=arr[i]){
            cnt++; 
        }
    }
    cout << cnt-1;
    return 0;
}



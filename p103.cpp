#include "bits/stdc++.h"

using namespace std;
int arr[101];
int dff[101];
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int N;
    cin >> N;
    int sum = 0;
    for(int i=0;i<N;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    int avg = sum/N;
    for(int i=0;i<N;i++){
        dff[i] = arr[i]-avg;
    }
    int cnt = 0;
    for(int i=0;i<N-1;i++){
        if(dff[i]!=0){
            dff[i+1] += dff[i];   
            cnt++;  
        }
    }
    cout << cnt;

}
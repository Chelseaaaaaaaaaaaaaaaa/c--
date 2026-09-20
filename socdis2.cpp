#include "bits/stdc++.h"

using namespace std;
struct cow{
    int pos;
    int infected;
};
bool comp(cow &a, cow &b){
    return a.pos<b.pos;
}
cow arr[1001];
int main(){
    freopen("socdist2.in", "r", stdin);
    freopen("socdist2.out", "w", stdout);
    int N;
    cin >> N;
    int cnt = N;
    for(int i=0;i<N;i++){
        cin >> arr[i].pos >> arr[i].infected;
        if(arr[i].infected==0){
            cnt--;
        }
    }
    sort(arr,arr+N,comp);
    int r = INT_MAX;
    for(int i=0;i<N-1;i++){
        if(arr[i].infected != arr[i+1].infected){
            r = min(r,abs(arr[i].pos-arr[i+1].pos)); 
            
        }
    }
    r--;
    for(int i=0;i<N-1;i++){
        if(arr[i].infected == 1&&arr[i+1].infected==1){
            if(abs(arr[i].pos-arr[i+1].pos)<=r){
                cnt--;
            }
        }
    } 
    cout << cnt;
}



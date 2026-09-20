#include "bits/stdc++.h"

using namespace std;
int arr[50001];
int N, K; 

bool check(int radius){ //根据半径需要多少奶牛
    int cnt = 0;
    int left = 0;
    while(left < N){
        cnt++;
        int curr = left + 1; 
        while(curr < N && arr[curr]-arr[left] <= 2*radius){
            curr++;

        }
        left = curr;
    }
    return cnt <= K;
}
int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    sort(arr,arr+N);
    int left = 0; 
    int right = arr[N-1]-arr[0];
    int ans = arr[N-1];
    while(left <= right){
        int mid = left + (right-left)/2;
        if(check(mid)){
            ans = mid;
            right = mid-1;

        }else{
            left = mid+1;
        }
    }
    cout << ans;
    return 0;
}
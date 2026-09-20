#include "bits/stdc++.h"

using namespace std;

int N, Q;
int arr[100001];

int cntHayvales(int limit){
    if(arr[0] > limit){
        return 0;
    }
    int left=0, right = N-1;
    int ans = 0;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(arr[mid] <= limit){
            ans = mid; //默认maximum，因为sort过了
            left = mid+1;
        }else{
            right = mid-1;
        }

    }
    return ans+1; //个数（ans原来是下标）
}

int main(){
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> Q;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    sort(arr,arr+N);
    for(int i=0;i<Q;i++){
       int a,b;
       cin >> a >> b;
       cout << cntHayvales(b)-cntHayvales(a-1) << endl;
    }


    return 0;
}
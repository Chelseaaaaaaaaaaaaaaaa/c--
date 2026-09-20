#include "bits/stdc++.h"

using namespace std;
int arr[100001];
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int N,L;
    cin >> N >> L;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    sort(arr,arr+N,greater<int>());
    for(int h=N;h>=0;h--){
        int cnt = 0;
        bool isBreak = false;
        for(int i=0;i<h;i++){
            if(arr[i]>=h){
               continue;
            }else if (arr[i]==h-1){
                cnt++;
            }else{
                isBreak = true;
                break;
            }
        }
        if(!isBreak){
           if(cnt<=L){
                cout << h;
                return 0;
           }
        }
    }
    return 0;
}



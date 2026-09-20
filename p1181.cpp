#include "bits/stdc++.h"

using namespace std;
int A[100001];
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int N,M;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> A[i]; 
    }
    int cnt = 1; //最少划分多少段数
    int sum = 0;//判断和是否
    for(int i=0;i<N;i++){
        if(sum+A[i]> M){ //如果和加上现在a[i]超过M的话
            cnt++;//加一个段数
            sum = A[i];//和初始化成a[i]
        }else{
            sum += A[i]; //如果没有超过M, 和加上a[i]
        }
    }
    cout << cnt;
    return 0;
}
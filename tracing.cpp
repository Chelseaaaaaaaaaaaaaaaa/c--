#include "bits/stdc++.h"

using namespace std;
int a[30001];
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int N;
    string cow;
    cin >> N >> cow;
    cow = " "+cow;
    int cnt=0;
    int m = 0;
    int c1 = -1,c2=-1; //记录最左边和最右边分别有多少个1
    for(int i=1;i<=N+1;i++){
       if(cow[i]=='1'){
        cnt++; //cnt计算连续有多少个1
       }else if(cnt){
        if(cnt == i-1){
            c1 = cnt, cnt=0;
        }else if(i>N){
            c2 = cnt, cnt = 0;
        }else{
            a[++m]= cnt, cnt=0;
        }
       } 
    }

    int mini = INT_MAX;
    for(int i=1;i<=m;i++){
        mini = min(mini,a[i]);
    }
    int maxday = 0;
    if(mini %2==0){
        maxday = mini/2-1;
    }
    if(mini%2==1){
        maxday = mini/2;
    }
    if(c1 != -1){
        maxday = min(c1-1,maxday);
    }
    if(c2 != -1){
        maxday = min(c2-1,maxday);
    }
    int ans = 0;
    for(int i=1;i<=m;i++){
        ans += (a[i]-1)/(2*maxday+1)+1;

    }
    if(c1!=-1){
       ans += (c1-1)/(2*maxday+1)+1; 
    }
    if(c2!=-1){
        ans += (c2-1)/(2*maxday+1)+1;
    }
    cout << ans;
    return 0;
}



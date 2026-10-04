#include "bits/stdc++.h"

using namespace std;
int prefix[50001];
int minr[8];
int maxr[8];
int arr[50001];
void buildPrefixsum(int arr1[],int n){
    for(int i=0;i<8;i++){
        minr[i] = INT_MAX;
    }
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+arr1[i];
        prefix[i] %= 7;
        maxr[prefix[i]]=i;
        minr[prefix[i]] = min(i,minr[prefix[i]]);
    }
}
int main(){
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    buildPrefixsum(arr,N);
    int maxnum = INT_MIN;
    for(int i=0;i<8;i++){
        maxnum = max(maxnum,maxr[i]-minr[i]);
    }
    cout << maxnum;
    return 0;
}



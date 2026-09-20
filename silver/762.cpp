#include "bits/stdc++.h"

using namespace std;
int minn[100001];
int prefix[100001];
int arr[100001];
double avg[100001];
void buildPrefixsum(int arr1[],int n){
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+arr1[i];
    }
}
int main(){
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);
    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    buildPrefixsum(arr,N);
    minn[N]=arr[N];
    for(int i=N-1;i>=1;i--){
        minn[i]=min(minn[i+1],arr[i]);
    }
    double maxnum = INT_MIN;
    for(int i=1;i<=N-2;i++){
        avg[i] = 1.0 * (prefix[N]-prefix[i]-minn[i+1])/(N-i-1);
        maxnum = max(avg[i],maxnum);
    }
    int cnt = 0;
    for(int i=1;i<=N-2;i++){
        if(avg[i]==maxnum){
            cout << i << endl;
        }
    }

    return 0;
}



#include "bits/stdc++.h"

using namespace std;
int cow[101];
int main(){
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> cow[i];
    }
    if(cow[1]>0){
        cout << -1;
        return 0;
    }else{
        cow[1]=0;
    }
    for(int i=N-1;i>=1;i--){
        if(cow[i]!=-1 && cow[i+1]!=-1 && cow[i]+1!= cow[i+1]){
            cout << -1;
            break;
        }
        if(cow[i]==-1&&cow[i+1]>0){
            cow[i]=cow[i+1]-1;
        }
    }
    int minn = 0;
    for(int i=1;i<=N;i++){
        if(cow[i]==0){
            minn++;
        }
    }
    int maxn = minn;
    for(int i=1;i<=N;i++){
        if(cow[i]==-1){
            maxn++;
        }
    }
    cout << minn << " "<< maxn;
}



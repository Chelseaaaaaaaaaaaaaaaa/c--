#include "bits/stdc++.h"

using namespace std;
int b[1005];
int a[1005];
int ans[1005];
int main(){
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    int N;
    cin >> N;
    for(int i=1;i<=N-1;i++){
        cin >> b[i];
    }
    for(int i=1;i<=N;i++){
        a[1]=i;
        ans[1]=i;
        for(int j=2;j<=N;j++){
            a[j]=b[j-1]-a[j-1];
            ans[j]=a[j];
        }
        sort(a+1,a+1+N); 
        bool flag = true;
        for(int j=1;j<=N;j++){
            if(a[j]!=j){
                flag = false;
                break;
            }
        }
        if(flag){
            for(int j=1;j<N;j++){
                cout << ans[j]<<" ";
            }
            cout << ans[N];
            break;
        }

    }
    return 0;
}
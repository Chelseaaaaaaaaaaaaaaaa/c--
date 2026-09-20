#include "bits/stdc++.h"

using namespace std;
int a[21];
int b[21];
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    for(int i=0;i<N;i++){
        cin >> b[i];
    }
    sort(a,a+N);
    sort(b,b+N);
    long long ans = 1;
    int number = N;
    for(int i=0;i<N;i++){
        int cnt = 0;
       for(int j=i;j<N;j++){
        if(a[j]<=b[i]){
            cnt++;
        }
       }
        ans = ans *cnt;
    }
    cout << ans;
    return 0;
}
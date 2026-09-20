#include "bits/stdc++.h"

using namespace std;
char arr[1002][1002];
int cnt[1002][1002];
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int N,M;
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(arr[i][j]=='C'){
                cnt[i-1][j]++;
                cnt[i][j-1]++;
                cnt[i][j+1]++;
                cnt[i+1][j]++;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(arr[i][j]=='G'){
                if(cnt[i][j]>=2){
                    ans++;
                }
                if(cnt[i][j]==2&&cnt[i+1][j+1]==2&&arr[i][j]=='G'&&arr[i][j+1]=='C'&&arr[i+1][j]=='C'&&arr[i+1][j+1]=='G'){
                    ans--;
                }
                if(cnt[i][j]==2&&cnt[i+1][j-1]==2&&arr[i][j-1]=='C'&&arr[i][j] == 'G'&&arr[i+1][j-1]=='G'&&arr[i+1][j]=='C'){
                    ans--;
                }
            }
        }
    }
    cout << ans;
    return 0;
}



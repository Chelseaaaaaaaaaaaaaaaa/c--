#include "bits/stdc++.h"

using namespace std;

void solve(){
    int n,a,b;
    cin >> n >> a >> b;
    string s[1001];
    for(int i=0;i<n;i++){
        cin >> s[i];
        for(auto &x:s[i]){ //需要更改x的值
            if(x=='W'){
                x=0;
            }else if(x=='G'){
                x=1;
            }else if(x=='B'){
                x=2;
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i][j]==2){
                ans++;
                s[i][j]--;
                if(i<b||j<a||!s[i-b][j-a]){
                    cout <<-1 << endl;
                    return;
                }
                s[i-b][j-a]--;
            }
        }
            
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i][j]){
                ans++;
                s[i][j]--;
                if(i+b<n&&j+a   <n&&s[i+b][j+a]){
                    s[i+b][j+a]--;
                }
            }
        }
    }
    cout << ans << endl;
}
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
    return 0;
}



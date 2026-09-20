#include "bits/stdc++.h"

using namespace std;
char canvas[11][11];
bool isAppeared[60];
bool ans[60];
void check(int &a){
    int top= INT_MAX;
    int left = INT_MAX;
    int bottom = INT_MIN;
    int right = INT_MIN;

    for(int i=0;i<11;i++){
        for(int j=0;j<11;j++){
            if(canvas[i][j]==a){
                top = min(i,top);
                left = min(j,left);
                bottom = max(i,bottom);
                right = max(j,right);
            }
        }
    }
    for(int i=top;i<=bottom;i++){
        for(int j=left;j<=right;j++){
            if(canvas[i][j]!=a){
                ans[canvas[i][j]] = false;
            }
        }
    } 
}
int main(){
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> canvas[i][j];
            isAppeared[canvas[i][j]]= true;
            ans[canvas[i][j]] = true;
        }
    }
    int cnt = 0;
    for(int i='1';i<='9';i++){
           if(isAppeared[i]){
            check(i);
        }
    }
    for(int i='1';i<='9';i++){
        if(ans[i]){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
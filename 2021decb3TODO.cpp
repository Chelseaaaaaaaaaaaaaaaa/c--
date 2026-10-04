#include "bits/stdc++.h"
using namespace std;

string a[51];

int change1(int n) {
    // 改变1次方向
    bool ok = true;
    int cnt = 0;
    for (int i = 0; i < n && ok; i++) {
        if (a[0][i] != '.') ok = 0;
    }
    for (int i = 0; i < n && ok; i++) {
        if (a[i][n - 1] != '.') ok = 0;
    }
    if (ok) cnt++;

    ok = true;
    for (int i = 0; i < n; i++) {
        if (a[i][0] != '.') ok = 0;
    }
    for (int i = 0; i < n; i++) {
        if (a[n-1][i] != '.') ok = 0;
    }
    if (ok) cnt++;

    return cnt;
}

int change2(int n) {
    // 改变2次方向
    int cnt = 0;
    for(int j=1;j<=n-2;j++){
        bool ok = true;
        for(int i=0;i<=j&&ok;i++){
            if(a[0][i] != '.'){
                ok = false;
            }
        }
        for(int i=0;i<=n-1 && ok;i++){
            if(a[i][j]!='.'){
                ok = false;
            }
        }
        for(int i=j;i<=n-1 && ok;i++){
            if(a[n-1][i] != '.'){
                ok = false;
            }
        }
        if (ok){
            cnt++;
        }

        ok = true;
        for(int i=0;i<=j&&ok;i++){
            if(a[i][0]!='.'){
                ok = false;
            }
        }

        for(int i=0;i<=n-1&&ok;i++){
            if(a[j][i] != '.'){
                ok = false;
            }
        }

        for(int i=j;i<=n-1;i++){
            if(a[i][n-1] != '.'){
                ok = false;
            }
        }

        if(ok){
            cnt++;
        }
    }
    return cnt;
    
}

int change3(int n) {
    // 改变3次方向
    int cnt = 0;
    for(int x=1;x<=n-2;x++){
        for(int y=1;y<=n-2;y++){
            bool ok = true;
            for(int i=0;i<=x&&ok;i++){
                if(a[0][i]!='.'){
                    ok = false;
                }
            }

            for(int i=0;i<=y&&ok;i++){
                if(a[i][x] != '.'){
                    ok = false;
                }
            }

            for(int i=x;i<=n-1&&ok;i++){
                if(a[y][i] != '.'){
                    ok = false;
                }
            }

            for(int i=y;i<=n-1&&ok;i++){
                if(a[i][n-1] != '.'){
                    ok = false;
                }
            }

            if(ok){
                cnt++;
            }

            ok = true;
            for(int i=0;i<=x&&ok;i++){
                if(a[i][0] != '.'){
                    ok = false;
                }
            }
            
            for(int i=0;i<=y&&ok;i++){
                if(a[x][i] != '.'){
                    ok = false;
                }
            }

            for(int i=x;i<=n-1&&ok;i++){
                if(a[i][y] != '.'){
                    ok = false;
                }
            }

            for(int i=y;i<=n-1&&ok;i++){
                if(a[n-1][i] != '.'){
                    ok = false;
                }
            }
            if(ok){
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int ans = 0;
        if (k == 1) {
            ans = change1(n);
        }
        if (k == 2) {
            ans = change1(n) + change2(n);
        }
        if (k == 3) {
            ans = change1(n) + change2(n) + change3(n);
        }
        cout << ans << endl;
    }

    return 0;
}
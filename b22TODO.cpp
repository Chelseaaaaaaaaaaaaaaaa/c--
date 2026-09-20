#include "bits/stdc++.h"
using namespace std;

char canvas[22][22];
char s1[22][22], s2[22][22], s3[22][22], s4[22][22];
int K, N;

void rotate() {
    for (int i = 1; i <= K; i++)
        for (int j = 1; j <= K; j++) {
            s2[j][K + 1 - i] = s1[i][j];  
        }

    for (int i = 1; i <= K; i++)
        for (int j = 1; j <= K; j++) {
            s3[j][K + 1 - i] = s2[i][j];
        }

    for (int i = 1; i <= K; i++)
        for (int j = 1; j <= K; j++) {
            s4[j][K + 1 - i] = s3[i][j];  
        }
}

int check(int x, int y, char t[][22]) {
    for (int i = 1; i <= K; i++)
        for (int j = 1; j <= K; j++)
            if (t[i][j] == '*') {
                int ok = 1;
                // TODO
                for(int p=1;p<=K;p++){
                    for(int q=1;q<=K;q++){
                        int nx = x+p-i;
                        int ny = y+q-j;
                        if(nx<=0|| nx>N || ny<=0||ny>N){
                            ok = 0;
                            break;
                        }
                        if(t[p][q] == '*' && canvas[nx][ny]!='*'){
                            ok=0;
                            break;
                        }
                        if(ok==0){
                            break;
                        }
                    }
                }

                if (ok == 1) return 1;
            }
    return 0;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> canvas[i][j];
        }
    }

    cin >> K;
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= K; j++) {
            cin >> s1[i][j];
        }
    }

    rotate();

    int ans = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            if (canvas[i][j] == '*') {
                int res = check(i, j, s1) || check(i, j, s2) || check(i, j, s3) || check(i, j, s4);
                ans = min(ans, res);
            }
        }

    if (ans) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}

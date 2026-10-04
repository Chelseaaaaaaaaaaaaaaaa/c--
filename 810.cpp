#include "bits/stdc++.h"

using namespace std;
const int MAXN = 1e5 +1;
bool isMax[MAXN];
struct reststop{
    int x,c; //建立一个struct 里面是位置 加上tastiness
};
reststop st[100001];
int main(){
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    int L,N,rf,rb;
    cin >> L >> N >> rf >> rb;
    for(int i=0;i<N;i++){
        cin >> st[i].x >> st[i].c;
    }
    int maxc = 0;
    for(int i=N-1;i>=0;i--){
        if(st[i].c>maxc){
            isMax[i] = true;
            maxc = st[i].c;
        }
    }
    long long ans = 0,lastX = 0;
    for(int i=0;i<N;i++){
        if(isMax[i]){
            long long t = (st[i].x-lastX)*(rf-rb);
            ans += st[i].c * t;
            lastX = st[i].x;
        }
    }
    cout << ans;
    return 0;
}
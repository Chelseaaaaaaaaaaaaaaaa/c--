#include "bits/stdc++.h"

using namespace std;
struct cow{
    int pos,dir;
};

bool comp(const cow&a, const cow&b){
    if(a.pos != b.pos){
        return a.pos < b.pos;
    }
    return a.dir < b.dir;
}
cow p[1001];
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int N;
    cin >> N;
    char c;
    int x;
    int cnt=0;
    for(int i=0;i<N;i++){
        cin >> c >> x;
        p[i].pos = x;
        if(c=='L'){
            p[i].dir = 1;
            cnt++; //默认在最左边 所以所有的L都是正确的
        }else{
            p[i].dir = 0; 
        }
    }
    sort(p,p+N,comp);
    int maxcnt = cnt;
    for(int i=0;i<N;i++){
        if(p[i].dir > 0){
            cnt--;
        }else{
            cnt++;
            maxcnt = max(cnt,maxcnt);
        }
    }
    int ans = N-maxcnt;
    cout << ans << endl;
}



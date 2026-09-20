#include "bits/stdc++.h"

using namespace std;
struct interval{
    long long start, end;
};
interval p[100001];
bool comp(const interval &a, const interval &b){
    return a.start<b.start; //不会重叠说明start不一样
}

int N, M;

bool check(long long c){
    long long cnt = 0, begin = 0; 
    for(int i=0; i<M; i++){
        begin = max(begin, p[i].start);
        if(begin <= p[i].end){
            long long points = (p[i].end-begin)/c+1; //判断可以放多少个牛
            cnt += points;
            begin += points * c; //有多少个牛乘以c (距离)
        }
    }
    return cnt >= N;
}
int main(){
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> p[i].start >> p[i].end;
    }
    sort(p,p+M,comp);
    long long left = 0;
    long long right = p[M-1].end;
    long long ans;
    while(left <= right){
        long long mid = left + (right - left)/2;
        if(check(mid)){
            ans = mid;
            left = mid+1;
        }else{
            right = mid-1;
        }
    }

    cout << ans << endl;
    return 0;
}
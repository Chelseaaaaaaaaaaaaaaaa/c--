#include "bits/stdc++.h"

using namespace std;
struct cow{
    int value;
    int cnt;
};
cow arr[200001];
bool compsort(const cow &a, const cow &b){
    return a.value > b.value; 
}

struct cmp {  // �º��� functor
    bool operator()(const cow &a, const cow &b) {
        return a.value < b.value;
    }
};
priority_queue<cow, vector<cow>,cmp> pq;
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,M,K;
    cin >> N >> M >> K;
    for(int i=0;i<N;i++){
        cin >> arr[i].value >> arr[i].cnt;
    }
    long long ans = 0;
    sort(arr,arr+N,compsort);
    pq.push({INT_MAX,M});
    for(int i=0; i<N; i++){
        int num = arr[i].cnt;
        int cnts = 0;
        while(!pq.empty()){
            auto p = pq.top();
            if(p.value < arr[i].value + K){
                break;
            }
            int delta = min(p.cnt, num);
            p.cnt -= delta;
            num -= delta;
            cnts += delta;

            pq.pop();
            if(p.cnt !=0){
                pq.push(p);
            }
            if(!num){
                break;
            }
        }
        pq.push({arr[i].value,cnts});
        ans += cnts;

    }
    cout << ans << endl;
    return 0;
}



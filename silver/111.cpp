#include "bits/stdc++.h"

using namespace std;
set<int> years;
vector<int> interval;
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,K;
    cin >> N >> K;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        years.insert((a-1)/12+1);
    }

    int previous = 0;
    for(auto &b:years){
        interval.push_back(b-previous-1);
        previous = b;
    }

    sort(interval.begin(), interval.end(), greater<int>());
    int ans = 0;
    for(int i=0;i<K-1;i++){
        ans += interval[i];
    }
    cout << (previous -ans)*12;
    return 0;
}



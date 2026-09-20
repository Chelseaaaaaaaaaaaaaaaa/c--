#include "bits/stdc++.h"

using namespace std;
map<string,int> cow;
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string name, state;
        cin >> name >> state;
        if(name.substr(0,2)==state){
            continue;
        }
        string together = name.substr(0,2) + state;
        cow[together]++;
    }
    long long ans = 0;
    for(auto &kv:cow){
        string a = kv.first;
        int b = kv.second;
        string c = a.substr(2,2) + a.substr(0,2);
        ans += cow[c] * b;
    }
    cout << ans/2;
    return 0;
}



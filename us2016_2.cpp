#include "bits/stdc++.h"

using namespace std;
int ans[27];
int main(){
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int N;
    cin >> N;
    for(int i=0; i<N;i++){
        int cnt1[27] = {};
        int cnt2[27] = {};
        string s1,s2;
        cin >> s1 >> s2;
        for(int j=0;j<s1.length();j++){
            cnt1[s1[j]-'a']++;
        }
        for(int j=0;j<s2.length();j++){
            cnt2[s2[j]-'a']++;
        }
        for(int j=0;j<26;j++){
            ans[j] += max(cnt1[j],cnt2[j]);
        }

    }
    for(int i=0; i<26;i++){
        cout << ans[i] << endl;
    }
}



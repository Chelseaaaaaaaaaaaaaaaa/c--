#include "bits/stdc++.h"

using namespace std;
int main(){
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    string s;
    cin >> s;
    int ans = 0;
    for(int c = 'A';c<='Z';c++){
        int first = -1;
        int last = -1;
        for(int i=0; i<52;i++){
            if(s[i]==c){
               if(first == -1){
                first = i;
               }else{
                last = i;
                break;
               }
                
            }
        }
        int cnt[26] = {};
        for(int i=first+1;i<last;i++){
            cnt[s[i]-'A']++;
        }
        for(int i=0;i<26;i++){
            if(cnt[i]==1){
                ans++;
            }
        }
    }
    cout << ans/2;
    return 0;
}
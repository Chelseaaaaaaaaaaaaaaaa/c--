#include "bits/stdc++.h"

using namespace std;
map<string,int> m;
set<int,greater <int>>s;
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    string s;
    int len;
    cin >> s >> len;
    int start = 0;
    int cnt = 1;
    for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1]){
            cnt++;
        }else{
            string sub = s.substr(start,cnt);
            s.insert(cnt);
            cout << sub << endl;
            m[sub]++;
            start = i;
            cnt = 1;
        }
    }
    string sub1 = s.substr(start,cnt);
    s.insert(sub1);
    m[sub1]++;
    for(auto &kv:m){
        cout << kv.first << " " << kv.second << endl;
    }
    for(auto )


    
    cout << "hello";
    return 0;
}



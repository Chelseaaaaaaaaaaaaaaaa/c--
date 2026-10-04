#include "bits/stdc++.h"

using namespace std;
int s[27];
int m[27];
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    string s1, word;
    cin >> s1 >> word;
    for(int i=0;i<26;i++){
        s[i] = s1[i];
        m[s[i]-'a'] = i;
    }
    int cnt=1;
    for(int i=0;i<word.length()-1;i++){
        if(m[word[i]-'a']>=m[word[i+1]-'a']){
            cnt++;
        }
    }
    cout << cnt;
    return 0;

}
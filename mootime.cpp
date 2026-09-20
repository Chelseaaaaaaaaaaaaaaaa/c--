#include "bits/stdc++.h"
using ll = long long;

using namespace std;
ll cnt[26][26][26]; //统计连续的三个字母
bool pattern[26][26];//记录abb模式存不存在
ll ans;
int N;
string s,sbackup;
void removeOriginal(int start, int i){
    for(int j=start;j+2<N&&j<=i;j++){
        int x = s[j]-'a';
        int y = s[j+1] -'a';
        int z = s[j+2] -'a';
        cnt[x][y][z]--;
    }
}

void revoverOriginal(int start, int i){
    s[i] = sbackup[i];
    for(int j=start;j+2<N&&j<=i;j++){
        int x = s[j]-'a';
        int y = s[j+1] -'a';
        int z = s[j+2] -'a';
        cnt[x][y][z]++;
    }
}
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int F;
    cin >> N >> F;
    cin >> s;
    sbackup = s;
    for(int i=0;i<N-2;i++){
        int x= s[i]-'a';
        int y = s[i+1]-'a';
        int z = s[i+2]-'a';
        cnt[x][y][z]++;
    }

    for(int i=0;i<N;i++){
        int start = i-2;
        if(start<0){
            start = 0;
        }
        //int start = max(0,i-2);
        removeOriginal(start,i);

        for(int c=0;c<26;c++){
            s[i]=c+'a';
            for(int j=start;j+2<N&&j<=i;j++){
                int x = s[j]-'a';
                int y = s[j+1] -'a';
                int z = s[j+2]-'a';
                cnt[x][y][z]++;
            }
            for(int g=0;g<26;g++){
                for(int f=0;f<26;f++){
                    if(!pattern[g][f] && g!=f){
                        if(cnt[g][f][f]>=F){
                            ans++;
                            pattern[g][f]=true;
                        }
                    }
                }
            }
            for(int j=start;j+2<N&&j<=i;j++){
                int x = s[j]-'a';
                int y = s[j+1]-'a';
                int z = s[j+2]-'a';
                cnt[x][y][z]--;
            }
        }
        revoverOriginal(start,i);
    }
    cout << ans<<endl;
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            if(pattern[i][j]){
                char A = i+'a';
                char B = j+'a';
                cout << A << B << B << endl;
            }
        }
    }
    return 0;
}



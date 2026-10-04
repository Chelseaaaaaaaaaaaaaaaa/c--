#include "bits/stdc++.h"

using namespace std;
string names[101];
string s[101];
int num[101];
int ans[101][101];
int N;
int findindex(string x){
    for(int i=0;i<N;i++){
        if(s[i]==x){
            return i;
        }
    }
    return -1;
}
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int K;
    cin >> K >> N;
    for(int i=0;i<N;i++){
        cin >> names[i];
    }
    for(int i=0;i<K;i++){
        for(int j=0;j<N;j++){
            cin >> s[j];
            num[j]=findindex(s[j]);
        }
        for(int j=1;j<N;j++){
            if(s[j-1]>s[j]){
                cout << j << " ";
                for(int a=0;a<j;a++){
                    for(int b=j;b<N;b++){
                        cout << a << " " << b << endl;
                        ans[num[a]][num[b]]=1;
                        ans[num[b]][num[a]] = 2; //d本来初始化就是0，所以设成1，2
                    }
                }
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j){
                cout << 'B';
            }else if (ans[i][j]==0){
                cout << '?';
            }else if(ans[i][j]==1){
                cout << 0;
            }else{
                cout << 1;
            }
        }
        cout << endl;
    }


    return 0;
}



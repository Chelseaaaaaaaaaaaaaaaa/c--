#include "bits/stdc++.h"

using namespace std;
int main(){
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    int N,K;
    cin >> N >> K;
    string words1;
    int cnt = 0;
    for(int i=0;i<N;i++){
        cin >> words1;
        if(cnt+words1.length() <= K){
            if(cnt > 0){
               cout << " ";
            }
            
        }else{
            cout <<endl;
            cnt = 0;
        }
        cout << words1;
        cnt += words1.length();
    }
    return 0;
}



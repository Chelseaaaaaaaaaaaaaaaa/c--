#include "bits/stdc++.h"

using namespace std;
int a[100001];
int b[100001];
int prefix[100002];
int suffix[100002];
void prefixSum(string fence1,int N1){
    for(int c='A';c<='Z';c++){
        int cnt = 0;
        bool brushdown = false;
        for(int i=1;i<=N1;i++){
            if(fence1[i-1]==c){
                if(!brushdown){
                    cnt++;
                    brushdown = true;
                }
            }else if(fence1[i-1]<c){
                brushdown = false;
            }
            prefix[i]+= cnt;
        }
    }
}

void suffixSum(string fence1,int N1){
    for(int c='A';c<='Z';c++){
        int cnt = 0;
        bool brushdown = false;
        for(int i=N1;i>=1;i--){
            if(fence1[i-1]==c){
                if(!brushdown){
                    cnt++;
                    brushdown = true;
                }
            }else if(fence1[i-1]<c){
                brushdown = false;
            }
            suffix[i]+= cnt;
        }
    }
}
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int N,Q;
    cin >> N >> Q;
    string fence;
    cin >> fence;
    for(int i=1;i<=Q;i++){
        cin >> a[i] >> b[i];
    }
    prefixSum(fence,N);
    suffixSum(fence,N);
    for(int i=1;i<=Q;i++){
        cout << prefix[a[i]-1]+suffix[b[i]+1] << endl; 
    }
    return 0;
}



#include "bits/stdc++.h"

using namespace std;
int prefix1[100001];
int prefix2[100002];
int prefix3[100003];
int main(){
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int N,Q;
    cin >> N >> Q;
    for(int i=1;i<=N;i++){
        int num;
        cin >> num;
        prefix1[i]=prefix1[i-1];
        prefix2[i]=prefix2[i-1];
        prefix3[i]=prefix3[i-1];
        if(num==1){
            prefix1[i]++;
        }else if(num==2){
            prefix2[i]++;
        }else{
            prefix3[i]++;
        }
    }
    for(int i=0;i<Q;i++){
        int start,end;
        cin >> start >> end;
        cout << prefix1[end]-prefix1[start-1] << " ";
        cout << prefix2[end]-prefix2[start-1] << " ";
        cout << prefix3[end]-prefix3[start-1] << endl;
    }
    return 0;
}



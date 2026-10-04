#include "bits/stdc++.h"

using namespace std;
struct aircon{
    int a,b,p,m;
};
string base10to2(int num,int len){
    int r[100] = {};
    int cnt = 0;
    while(num>0){
        r[cnt] = num%2;
        num/=2;
        cnt++;
    }

    string s = "";
    for(int i=cnt-1;i>=0;i--){
        s+=r[i]+'0';
    }
    for(int i=0;i<len-cnt;i++){
        s='0'+s;
    }

    return s;
}

int c[110];
aircon air[11];
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int n,m;
    cin >> n >> m;
    int t1,t2,t3;
    for(int i=1;i<=n;i++){
        cin >> t1 >> t2 >> t3;
        for(int j=t1;j<=t2;j++){
            c[j]=t3;
        }
    }
    for(int i=0;i<m;i++){
        cin >> air[i].a >> air[i].b >> air[i].p >> air[i].m;
     }
    int ans=INT_MAX;
    int cnt = pow(2,m);
    for(int i=0;i<cnt;i++){
        int reduce[110] = {};
        int money = 0;
        string status = base10to2(i,m);
        for(int j=0;j<m;j++){
            if(status[j]=='1'){
                for(int k=air[j].a;k<=air[j].b;k++){
                    reduce[k] += air[j].p;
                }
                money += air[j].m;
            }
        }
        bool ok = true;
        for(int j=1;j<=100;j++){
            if(reduce[j]<c[j]){
                ok = false;
            }
        }
        if(ok){
            ans = min(ans,money);
        }
    }
    cout << ans;
    return 0;
}


  
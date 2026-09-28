#include "bits/stdc++.h"
using namespace std;
int n,m,f[100001];
string s;
int cnt;

int find(int v){
    if(f[v]==v) return v;
    f[v]=find(f[v]);
    return f[v];
}

void merge(int u,int v){
    u=find(u);
    v=find(v);
    if(u!=v){
        f[v]=u;
    }
}

int main(){
    ios::sync_with_stdio(false);
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        if(s[x-1]==s[y-1]){
            merge(x,y);
        }
    }
    for(int i=0;i<m;i++){
        int a,b;
        char c;
        cin >> a >> b >> c;
        if(find(b)==find(a) && s[a-1]!=c){
            cout << 0;
        }else{
            cout << 1;
        }
    }
    return 0;
}

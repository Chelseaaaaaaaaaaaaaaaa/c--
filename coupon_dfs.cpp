#include "bits/stdc++.h"

using namespace std;
vector<int> coupon;
int f[36];

int dfs(int pos){
    if(f[pos]>0){
        return f[pos];
    }
    if(pos==0){
        return coupon[0];
    }else if(pos == 1){
        return max(coupon[0],coupon[1]);
    }else{
        f[pos] =  max(dfs(pos-1),dfs(pos-2)+coupon[pos]);
        return f[pos];
    }
}

int dfs2(int pos){
    if(f[pos]>0){
        return f[pos];
    }
    if(pos >= coupon.size()){
        return 0;
    }else{
        f[pos] = max(coupon[pos]+dfs2(pos+2),dfs2(pos+1));
        return f[pos];
    }

}

int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string c;
    getline(cin,c);
    stringstream ss(c);
    int temp;
    while(ss >> temp){
        coupon.push_back(temp);
    }
    cout << dfs2(0);


    return 0;
}



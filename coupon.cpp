#include "bits/stdc++.h"
using namespace std;

vector<int> coupon;


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
    //sum.resize(coupon.size());
    vector<int> sum(coupon.size());
    sum[0] = coupon[0];
    sum[1] = max(coupon[0],coupon[1]);
    for(int i=2;i<coupon.size();i++){
        sum[i] = max(sum[i-1],sum[i-2]+coupon[i]);
    }
    


    cout << sum[sum.size()-1];
    return 0;
}




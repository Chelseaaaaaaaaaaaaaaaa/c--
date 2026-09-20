#include "bits/stdc++.h"

using namespace std;
struct cow{
    int first;
    int second;
};
int ans[101];
cow grass[101];
int N,M;
bool check(int cows,int seed){
    for(int i=1;i<=M;i++){
        if(grass[i].second == cows && ans[grass[i].first]==seed){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    cin >> N >> M;
    for(int i=1;i<=M;i++){
        cin >> grass[i].first >> grass[i].second;
        if(grass[i].first>grass[i].second){
            swap(grass[i].first,grass[i].second);
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(check(i,j)){
                ans[i]=j;
                break;
            }
        }
    }
    for(int i=1;i<=N;i++){
        cout << ans[i];
    }
}



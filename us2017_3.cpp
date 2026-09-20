#include "bits/stdc++.h"

using namespace std;
struct cow{
    int arrive;
    int answer;
};
cow arr[101];
bool comp(const cow&a, const cow&b){
    return a.arrive < b.arrive;
}
int main(){
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i].arrive >> arr[i].answer;
    }
        
    sort(arr,arr+N,comp);
    int last=0;
    for(int i=0;i<N;i++){
        last = max(last,arr[i].arrive);
        last += arr[i].answer;
    }
    cout << last;
    return 0;
}
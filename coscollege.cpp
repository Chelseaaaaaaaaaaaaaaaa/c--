#include "bits/stdc++.h"

using namespace std;
long long money[10*10*10*10*10+1];
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> money[i];
    }
    sort(money,money+N);
    long long max = 0;
    long long tuition = 0;
    for(int i=0;i<N;i++){
        long long sum = 0;
        sum = money[i]*(N-i);
        if(sum>max){
            max = sum;
            tuition = money[i];
        }
    }
    cout << max << " " << tuition;
    return 0;
}
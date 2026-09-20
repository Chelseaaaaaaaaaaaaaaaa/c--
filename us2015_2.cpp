#include "bits/stdc++.h"

using namespace std;
int sp[101];
int cow[101];
int main(){
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int n,m;
    int seg,spe;
    int start = 1;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> seg >> spe;
        for(int i=start;i<start+seg;i++){
            sp[i] = spe;
        }
        start += seg;
    }
    start = 1;
    for(int i=0;i<m;i++){
        cin >> seg >> spe;
        for(int i=start;i<start+
            seg;i++){
            cow[i] = spe;
        }
        start += seg;
    }
    int max = 0;
    for(int i=1;i<=100;i++){
        if(cow[i]-sp[i] > max){
            max = cow[i]-sp[i];
        }
    }
    cout << max;
}



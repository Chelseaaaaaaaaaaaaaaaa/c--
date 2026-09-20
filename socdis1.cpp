#include "bits/stdc++.h"

using namespace std;
int main(){
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);
    int N;
    cin >> N;
    string pos;
    cin >> pos;
    int longest = 0;
    int seclongest = 0;
    int left = 0;
    int right = 0;
    int prev = -1;
    int D = INT_MAX;
    for(int i=0;i<N;i++){
        if(pos[i]=='1'){
               if(prev == -1){
                    left = i;
               }else{
                    D = min(D,i-prev);
                    if(i-prev>longest){
                        seclongest = longest;
                        longest = i-prev;
                    }else if(i-prev>seclongest){
                        seclongest = i-prev;
                }
            }
                prev = i;
        }
        
    }
    if(prev == -1){
        cout <<  N-1;
        return 0;
    }else{
        right = N-1-prev;
    }
    int d1 = 0;
    d1 = max(d1,longest/3);
    d1 = max(d1,left/2);
    d1 = max(d1,right/2);
    d1 = max(d1,min(left,right)); ///离位置最近
    d1 = max(d1,min(left,longest/2));
    d1 = max(d1,min(right,longest/2));
    d1 = max(d1,min(longest/2,seclongest/2));
    cout << min(D,d1)<<endl; ///不能把d变得更大
    
    return 0;
}



///#include <bits/stdc++.h>
#include "macstdc++.h"
using namespace std;
int arr[5001];
int main()
{
    int N,M;
    cin >> N >> M;
    for(int i=2; i<=M;i++){
        for(int j=1;j<=N;j++){
            if(j%i==0){
                if(arr[j]==0){
                    arr[j] = 1;
                }else{
                    arr[j] = 0;
                }
            }
        }
    }
    int cnt = 0;
    for(int i=1; i<=N;i++){
        if(arr[i]==0){
            if(cnt==0){
                cout << i;
            }else{
                cout << "," << i;
            }
            cnt++;
        }
    }
    
 
}
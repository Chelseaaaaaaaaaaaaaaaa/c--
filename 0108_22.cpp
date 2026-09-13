#include <bits/stdc++.h>
///#include "macstdc++.h"
using namespace std;
int arr[40][40];
int main(){
    int N;
    cin >> N;
    int r=0,c=N-1;
    N = 2*N-1;
    int num = N*N;
    arr[r][c] = 1;
    for(int i=2;i<=num;i++){
        if(r == 0&&c != N-1){
            r = N-1;
            c++;
        }else if(c == N-1&& r!=0){
            c = 0;
            r--;
        }else if((r == 0 && c == N-1)||(arr[r-1][c+1] > 0)){
            r++;
        }else{
            r--;
            c++;
        }
        arr[r][c] = i;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
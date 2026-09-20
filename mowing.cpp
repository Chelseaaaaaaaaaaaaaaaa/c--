#include "bits/stdc++.h"

using namespace std;
int arr[2000][2000];
int main(){
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    int N;
    cin >> N;
    int ans = INT_MAX;
    int curRow = 1000, curCol = 1000;
    arr[curRow][curCol] = 1;
    for(int i=0;i<N;i++){
        char direction;
        int step = 0;
        int row = 0, col = 0;
        cin >> direction >> step;
        if(direction == 'N'){
            row = -1;
        }
        if(direction == 'S'){
            row = 1;
        }
        if(direction == 'W'){
            col = -1;
        }
        if(direction == 'E'){
            col = 1;
        }
        for(int j=0;j<step;j++){
            int t = arr[curRow][curCol] +1;
            curRow += row;
            curCol += col;
            if(arr[curRow][curCol] > 0){
                ans = min(ans, t-arr[curRow][curCol]);
            }
            arr[curRow][curCol] = t;
        }
    }
    if(ans == INT_MAX){
        cout << -1;
    }else{
        cout << ans;
    }

}
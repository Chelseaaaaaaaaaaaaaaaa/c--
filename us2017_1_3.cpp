#include "bits/stdc++.h"

using namespace std;
int arr[11][11];
void change(int a, int b){
    for(int i=a;i>=0;i--){
        for(int j=b;j>=0;j--){
            if(arr[i][j]==1){
                arr[i][j]=0;
            }else{
                arr[i][j]=1;
            }
        }
    }

}
int main(){
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    int N;
    cin >> N;
    string a;
    for(int i=0;i<N;i++){
        cin >> a;
        for(int j=0;j<N;j++){
            arr[i][j] = a[j]-'0';
        }

    }
    int cnt = 0;
    for(int i=N-1;i>=0;i--){
        for(int j=N-1;j>=0;j--){
            if(arr[i][j]==1){
                change(i,j);
                cnt++;
            }   
            
        }
    }
    cout << cnt;
}
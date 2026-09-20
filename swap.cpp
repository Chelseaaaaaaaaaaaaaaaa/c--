#include "bits/stdc++.h"

using namespace std;
int arr[101];
void reverse(int x,int y){
    while(x<y){
        swap(arr[x],arr[y]);
        x++;
        y--;
    }

}
int main(){
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    int N,K;
    cin >> N >> K;
    int a1,a2,b1,b2;
    cin >> a1 >> a2 >> b1 >> b2;
    for(int i=1;i<=N;i++){
        arr[i] = i;
    }
    for(int i=1;i<=K;i++){
        reverse(a1,a2);
        reverse(b1,b2);
        bool sorted = true;
        for(int j=1;j<=N;j++){
            if(arr[j]!=j){
                sorted = false;
                break;
            }
        }
        if(sorted){
            int r = K%i;
            for(int i=1;i<=r;i++){
                reverse(a1,a2);
                reverse(b1,b2);
            }
            break;
        }
    }

    for(int i=1;i<=N;i++){
        cout << arr[i]<<endl;
    }
    return 0;

}
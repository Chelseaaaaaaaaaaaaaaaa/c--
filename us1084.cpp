#include "bits/stdc++.h"

using namespace std;
int id[1001];
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int N;
    int even = 0;
    int odd = 0;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> id[i];
        if(id[i]%2 == 0){
            even++;
        }else{
            odd++;
        }
    }
    int group = 0;
    while (true){
        if(even >0 ){
            group++;
            even--;
        }
        else if(odd >=2){
            odd = odd -2;
            group++;
        }
        else{
            break;
        }
        if(odd > 0){
            group++;
            odd--;
        }
        else{
            break;
        }


    }    
    if(odd>0){
        group--;
    }


    cout << group;
    return 0;
}
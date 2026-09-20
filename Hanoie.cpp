#include "bits/stdc++.h"

using namespace std;
void hanoie(int n, char from, char via, char to){
    if(n==1){
        cout << from << " " << to << endl;
        return;
    }

    hanoie(n-1,from,to,via);
    hanoie(1,from,via,to);
    hanoie(n-1,via,from,to);
}
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    hanoie(n,'a','b','c');
    
    cout << "hello";
    return 0;
}



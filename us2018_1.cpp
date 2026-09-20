#include "bits/stdc++.h"

using namespace std;
int main(){
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    int a,x,y,b;
    cin >> a >> b >> x >> y;
    cout << min(abs(a-x)+abs(b-y),min(abs(y-a)+abs(b-x),abs(b-a)));
}
#include "bits/stdc++.h"

using namespace std;
int main(){
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int Xsmall = min(x1, x3);
    int Xlarge = max(x2,x4);
    int Ysmall = min(y1,y3);
    int Ylarge = max(y2,y4);
    int Xlength = Xlarge - Xsmall;
    int Ylength = Ylarge - Ysmall;
    int length =  max(Xlength,Ylength);
    cout << length * length;
    
}



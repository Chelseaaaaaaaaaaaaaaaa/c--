#include "bits/stdc++.h"

using namespace std;
int main(){
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    int x,y;
    cin >> x >> y;
    int sum = 0;
    int diff = 1;
    if(x<y){
        while (true){
            if(diff >= y-x){
                sum += y-x;
                break;
            }
            sum += abs(diff)*2;
            diff *= -2; 
        }
    }
    if(x>y){
        while (true){
            if (-diff >= x-y){
                sum += x-y;
                break;
            }
            sum += abs(diff)*2;
            diff *= -2;
        }
    }

    cout << sum;
    return 0;
}
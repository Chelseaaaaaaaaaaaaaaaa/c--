#include "bits/stdc++.h"

using namespace std;
int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        long long A,B,cA,cB,f;
        cin >> A >> B >> cA >> cB >> f;
        f = f - A - B/cB*cA;
        B = B%cB;
        if(f<=0){
            cout << 0 << endl;
        }else{
            long long b1 = cB-1-B;
            if(cA>=cB){
                cout << f+b1 << endl;
            }else{
                cout << f-(f-1)/cA*cA+b1+(f-1)/cA*cB << endl;
            }
        }
        
    }
    return 0;
}



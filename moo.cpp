#include "bits/stdc++.h"

using namespace std;
string arr[101];
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int Q;
    cin>>Q;
    for(int i=0;i<Q;i++){
        cin >> arr[i];
        int len = arr[i].length();
        if(arr[i].find("MOO")!=string::npos){
            cout << len-3<<endl;
        }else{
            if(arr[i].find("MOM")!=string::npos){
                cout << len-2<<endl;
            }
            else if(arr[i].find("OOO")!=string::npos){
                cout << len-2<<endl;
            }
            else if(arr[i].find("OOM")!=string::npos){
                cout << len-1<<endl;
            }else{
                cout << -1<<endl;
            }
        }
    }
    return 0;
}



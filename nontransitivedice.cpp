#include "bits/stdc++.h"

using namespace std;
int a[4];
int b[4];
int c[4];
bool xbeaty(int a[], int b[]){
    int awin=0,bwin=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(a[i]>b[j]){
                awin++;
            }else if(a[i]==b[j]){
                continue;
            }else{
                bwin++;
            }
        }
    }
    return awin > bwin;
}

bool check(){
    for(c[0]=1;c[0]<=10;c[0]++){
        for(c[1]=c[0];c[1]<=10;c[1]++){
            for(c[2]=c[1];c[2]<=10;c[2]++){
                for(c[3]=c[2];c[3]<=10;c[3]++){
                    if(xbeaty(b,c) && xbeaty(c,a)){
                        return true;
                    }
                }
            }
         }
    }
    return false;
}
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        for(int j=0;j<4;j++){
            cin >> a[j];
        }
        for(int j=0;j<4;j++){
            cin >> b[j];
        }
        if(!xbeaty(a,b)){
            for(int j=0;j<4;j++){
                swap(a[j],b[j]);
            }
        }
        if(check()){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }

    return 0;
}



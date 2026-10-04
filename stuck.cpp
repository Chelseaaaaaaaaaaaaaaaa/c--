#include "bits/stdc++.h"

using namespace std;
struct cow{
    int x;
    int y;
    int id;
    int len = INT_MAX;
};
bool compe(const cow &a, const cow &b){
    return a.y < b.y;
}

bool compn(const cow &a, const cow &b){
    return a.x < b.x;
}

bool cmpID(const cow &a, const cow &b){
    return a.id < b.id;
}

cow pN[51];
cow pE[51];
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int N;
    cin >> N;
    int cntN = 0;
    int cntE = 0;
    for(int i=0;i<N;i++){
        char dir;
        cin >> dir;
        if(dir == 'E'){
            cntE++;
            cin >> pE[cntE].x >> pE[cntE].y;
            pE[cntE].id = i;
        }else{
            cntN++;
            cin >> pN[cntN].x >> pN[cntN].y;
            pN[cntN].id = i;
        }
    }
    sort(pE+1,pE+1+cntE,compe);
    sort(pN+1,pN+1+cntN,compn);
    
    for(int i=1;i<=cntN;i++){
        for(int j=1;j<=cntE;j++){
            if(pE[j].len != INT_MAX){
                continue;
            }

            int lenx = pN[i].x - pE[j].x;
            int leny = pE[j].y - pN[i].y;
            if(lenx == leny || lenx < 0 || leny < 0){
                continue;
            }

            if(lenx < leny){
                pN[i].len = leny;
                break;
            }else{
                pE[j].len = lenx;
            }
        }
    }
    for(int i=1;i<=cntN;i++){
        pE[cntE + i] = pN[i];
    }
    sort(pE+1,pE+N+1,cmpID);
    for(int i=1;i<=N;i++){
        if(pE[i].len == INT_MAX){
            cout << "Infinity" << endl;
        }else{
            cout << pE[i].len << endl;
        }
    }
    return 0;
}



#include "bits/stdc++.h"

using namespace std;
string path[21];
bool turnRight(const char&a, const char&b){
    if(a=='N'&&b=='E'){
        return true;
    }else if(a=='E'&&b=='S'){
        return true;
    }else if(a=='S'&&b=='W'){
        return true;
    }else if(a=='W'&&b=='N'){
        return true;
    }
    return false;
}
int main(){
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> path[i];
        path[i] += path[i][0];
    }
    for(int i=0;i<N;i++){
        int cntR = 0;
        int cntL = 0;
        for(int j=0;j<path[i].length()-1;j++){
            if(path[i][j] == path[i][j+1]){
               continue;
            }else{
                if(turnRight(path[i][j],path[i][j+1])){
                    cntR++;
                }else{
                    cntL++;
                }
            }
                
        }
        if(cntR>cntL){
            cout << "CW";
        }else{
            cout << "CCW";
        }


        cout << endl;
    }

    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    return 0;
}



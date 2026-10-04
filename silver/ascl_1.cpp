#include "bits/stdc++.h"

using namespace std;
vector<string> p1;
vector<string> p2;
vector<string> draw;
string arr[8];
int transfer(char a){
    if(a == 'A'){
        return 1;
    }
    if(a=='T'){
        return 10;
    }
    if(a=='J'){
        return 11;
    }
    if(a=='Q'){
        return 12;
    }
    if(a=='K'){
        return 13;
    }
   return a-'0';
}
//把黑色的分成一组 把白色的分成一组

void play(vector<string> &player){
    for(int i=0;i<player.size();i++){
        for(int j=0;j<arr.length();j++){
            if(transfer(arr[j][0])-transfer(player[i][0])==1 && (arr[j][1] != player[i])){ //考虑颜色不同
                arr[j] = vec[i];
            }
        }
    }   
}
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    for(int i=0;i<7;i++){
        int t;
        cin >> t;
        p1.push_back(t);
    }
    for(int i=0;i<7;i++){
        int t;
        cin >> t;
        p2.push_back(t);
    }
    for(int i=0;i<4;i++){
        int t;
        cin >> t;
        arr[2*i] = t;
        arr[2*i+1] = 'E';
    }
    while(cin >> t){
        draw.push_back(t);
    }
    while(true){
        
    }
    cout << "hello";
    return 0;
}
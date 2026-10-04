#include "bits/stdc++.h"

using namespace std;
int f16to10(char a){
    if(a>='0' && a<='9'){
        return a -'0';
    }else{
        return a -'A'+10;
    }
}
char f10to16(int b){
    if(b>=0 && b<=9){
        return b+'0';
    }else{
        return (b-10)+'A';
    }
}
string findCreature(string guess,string distance){
    int row = f16to10(guess[0]);
    int col = f16to10(guess[1]);
    int dis1 = f16to10(distance[0]);
    int maxrow = 0;
    int maxcol = 0;
    int minrow = INT_MAX;
    int mincol = INT_MAX;
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            if(abs(i-row)+abs(j-col)==dis1){
                if(minrow == INT_MAX){ //第一次遇到的是最小值
                    minrow = i;
                    mincol = j;
                    continue;
                }
                maxrow = i;
                maxcol = j;
            }
        }
    }
    string min = "";
    min += f10to16(minrow);
    min += f10to16(mincol);
    string max = "";
    max += f10to16(maxrow);
    max += f10to16(maxcol);
    string ans;
    ans = min+" "+max;
    return ans;
    
}




int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    string loc;
    string dis;
    cin >> loc >> dis;
    cout << findCreature(loc,dis) << endl;
}
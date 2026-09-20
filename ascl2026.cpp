#include "bits/stdc++.h"

using namespace std;

int cnt[10];
bool vis[5]; // 记录符号用没用过
int target1;
string license;
long long solutions;

void toInteger(string plate){
    for(int i=0;i<plate.length();i++){
       if(plate[i] >= '0' && plate[i]<='9'){
        cnt[plate[i]-'0']++;
       } 
    }
}

long long getResult(long long a, long long b, int opr){

}

void dfs(long long current){
    if(current==target1){
        solutions++;
    }

    for(int opr =0; opr<5;opr++){
        
    }
}

int countSolutions(int target, string plate) {
    toInteger(plate);
    for(int digit=0;digit<10;digit++){
        if(cnt[digit] >0){
            cnt[digit]--;
            dfs(digit);
            cnt[digit]++;
        }
    }
}

int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> target1 >> license;
    countSolutions(target1, license);
    return 0;
}



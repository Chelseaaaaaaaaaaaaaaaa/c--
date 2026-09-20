#include "bits/stdc++.h"
using namespace std;

//a表示行；
//b表示列；
//c表示/对角线；
//d表示\对角线；
int a[100]; // 记录当前方案 
bool b[100],c[100],d[100];

int total; //总数
int n;     //N*N的格子

void dfs(int row) { // 第row行
    if(row==n+1){
        total++;

        if(total<=3){
            for(int i=1;i<=n;i++){
                cout <<a[i] << " ";
            }

            cout << endl;
        }

        return;
       
    }

    for(int col=1;col<=n;col++){
            if(!b[col] && !c[row+col] && !d[row-col+n]){
                a[row] = col;
                b[col] = true;
                c[row+col] = true;
                d[row-col+n] = true;

                dfs(row+1);
                b[col] = false;
                c[row+col] = false;
                d[row-col+n] = false;

            }
        }

}

int main() {
    cin>>n;
	dfs(1);
    cout<<total;
    return 0;
}

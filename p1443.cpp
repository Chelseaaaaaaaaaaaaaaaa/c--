#include "bits/stdc++.h"

using namespace std;
struct point{
    int x,y;
};
queue<point> p;
int arr[401][401];
int dir[8][2] = {{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2}};
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int n,m,startx,starty;
    cin >> n >> m >> startx >> starty;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            arr[i][j] = -1;
        }
    }
    p.push({startx,starty});
    arr[startx][starty]=0;
    while(!p.empty()){
        point curr = p.front();
        p.pop();
        for(int i=0;i<8;i++){
            int nrow = curr.x + dir[i][0];
            int ncol = curr.y + dir[i][1];
            //cout << nrow << " " << ncol <<endl;
            if(nrow > n || nrow < 1 || ncol > m || ncol < 1){
                continue;
            }
            if(arr[nrow][ncol]!=-1){
                continue;
            }
            p.push({nrow,ncol});
            arr[nrow][ncol] = arr[curr.x][curr.y]+1;
        }
        
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
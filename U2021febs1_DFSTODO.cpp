#include "bits/stdc++.h"
using namespace std;

const int DIR[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct point{
    int x;
    int y;
};

int pasture[3000][3000];  // pasture[i][j] = 0:无牛  1:有牛
int cnt[3000][3000]; // cnt[i][j] (i, j)四周有几头牛
bool vis[3000][3000];
int ans = 0;
queue<point> q;



// function declaration
void add(int x,int y);

void dfs(int x, int y) {
    if(cnt[x][y]!=3){
        return;
    }

    for(int i=0;i<4;i++){
        int nx = x + DIR[i][0];
        int ny = y + DIR[i][1];
        if(pasture[nx][ny]==0){
            ans++;
            add(nx,ny);
            break;
        }
    }

}


bool comfortable(int row, int col){
    if(pasture[row][col]==0){
        return false;
    }
    int adjacent = 0;
    for(int i=0;i<4;i++){
        int nx = row+DIR[i][0];
        int ny = col + DIR[i][1];
        adjacent += pasture[nx][ny];
    }
    if(adjacent==3){
        return true;
    }
    return false;
}

void check(int a, int b){
    if(comfortable(a,b)){
        q.push({a,b});
    }

    for(int i=0;i<4;i++){
        int nx = a+DIR[i][0];
        int ny = b+DIR[i][1];
        if(comfortable(nx,ny)){
            q.push({nx,ny});
        }
    }

}

void add(int x, int y) {
    pasture[x][y]=1;
    check(x,y);

    // dfs(x,y);

    // for(int i=0;i<4;i++){
    //     int nx = x+DIR[i][0];
    //     int ny = y+DIR[i][1];
    //     cnt[nx][ny]++;
    //     if(pasture[nx][ny]==1){
    //         dfs(nx,ny);
    //     }
    // }

    //bfs
    while(!q.empty()){
        point p = q.front();
        q.pop();
        int row = p.x, col=p.y;
        if(!comfortable(row,col)){
            continue;
        }
        
        for(int i=0;i<4;i++){
            int nx = row+DIR[i][0];
            int ny = col+DIR[i][1];
            cnt[nx][ny]++;
            if(pasture[nx][ny]==0){
                ans++;
                pasture[nx][ny]=1;
                check(nx,ny);
                break;
            }
        }
       

    }

}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        x += 1000;
        y += 1000;
        if (pasture[x][y] > 0) {
            ans--;
        } else {
            add(x, y);
        }
        cout << ans << endl;
    }

    return 0;
}

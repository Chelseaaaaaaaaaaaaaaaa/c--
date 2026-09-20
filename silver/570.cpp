#include "bits/stdc++.h"
using namespace std;
//点亮房间，从1出发上下左右移动，当前房间所对的开关都点亮


struct room{
    int x,y;
};

vector<room> r[101][101];
int n,m;

bool vis[101][101];
bool lit[101][101];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void bfs(){
    queue<room> q;
    q.push({1,1});
    vis[1][1] = true;
    lit[1][1] = true;

    while(!q.empty()){
        room curr = q.front();
        //cout << curr.x << " " << curr.y << endl;
        q.pop();
        vector<room> switches = r[curr.x][curr.y]; //room当前可以reach的其他房间
        for(auto s: switches){
            if(!lit[s.x][s.y]){ //turn on the switch
                lit[s.x][s.y] = true; // flip any switched in the room
                for(int i=0;i<4;i++){
                    int ncol = s.x+dir[i][0];
                    int nrow = s.y + dir[i][1];
                    if(ncol < 1 || ncol > n || nrow < 1 || nrow > n ){
                        continue;
                    }
                    if(vis[ncol][nrow]){//如果neighbor的房间亮了话，说明我能走进去
                        q.push({s.x,s.y}); //说明我们可以走到s
                        vis[s.x][s.y] = true;
                        break;
                    }

                }
            }
        }
        for(int i=0;i<4;i++){ // move
            int nx = curr.x + dir[i][0];
            int ny = curr.y + dir[i][1];
            if(nx<1||nx>n || ny<1 || ny>n){
                continue;
            }
            if(vis[nx][ny] || !lit[nx][ny]){
                continue;
            }
            q.push({nx,ny});
            vis[nx][ny] = true;

        }
    }
}
int main(){
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y,a,b;
        cin >> x >> y >> a >> b;
        r[x][y].push_back({a,b});
    }
    bfs(); //例外：房间没有机会回去，所以有些房间里没有被点亮
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(lit[i][j]){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
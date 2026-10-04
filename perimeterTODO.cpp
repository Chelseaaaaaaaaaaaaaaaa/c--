#include "bits/stdc++.h"
using namespace std;

struct point {
	int x, y;
};

bool icy[1001][1001], vis[1001][1001];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};  // ��������
int n, areaMax = 0, ansP = INT_MAX;

void bfs(int i, int j) {
	queue<point> q;
	q.push({i, j});
    vis[i][j] = true;
    int area = 1, perimeter = 0;

    while(!q.empty()) {
        point curr = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nrow = curr.x + dir[i][0];
			int ncol = curr.y + dir[i][1];
			// cout << nrow << " " << ncol << endl;
			if(nrow > n || ncol > n || ncol < 1 || nrow < 1){
				perimeter++;
				continue;
			}
			if(vis[nrow][ncol] == true){
				continue;
			}

			if(icy[nrow][ncol] == false){
				perimeter++;
				continue;
			}

			// if(icy[nrow][ncol] == true){
			// 	area++;
			// }
			area++;
			vis[nrow][ncol] = true;
			q.push({nrow,ncol});
		}
    }
	// areaMax = max(area,areaMax);
	// ansP = min(perimeter,ansp);
	if(areaMax == area){
		ansP = min(perimeter,ansP);
	}
	else if(area > areaMax){
		areaMax = area;
		ansP = perimeter;
	}

    // TODO update areaMax and ansP
}

/*
6
##....
....#.
.#..#.
.#####
...###
....##

13 22
*/
int main() {
	freopen("perimeter.in","r",stdin);
	freopen("perimeter.out","w",stdout);
    ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>n;
    
    for(int i=1; i<=n; i++) {
    	string s;
    	cin>>s;
    	for(int j=1; j<=n; j++) {
    		if(s[j-1] == '#') {
    			icy[i][j] = true;
			}
		}
	}
	
    for(int i=1; i<=n; i++) {
    	for(int j=1; j<=n; j++) {
    		if(icy[i][j] && !vis[i][j]) {
    			bfs(i, j);//搜索面积周长
			}
		}
	}

	cout<<areaMax<<" "<<ansP<<endl;

	return 0;
}

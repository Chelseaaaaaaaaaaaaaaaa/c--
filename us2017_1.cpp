#include "bits/stdc++.h"

using namespace std;
struct rect{
    int x1;
    int y1;
    int x2;
    int y2;
};
int area(rect a){
    return (a.x2-a.x1)*(a.y2-a.y1);
}
int crossarea(rect a,rect b){
    int l = max(a.x1,b.x1);
    int r = min(a.x2,b.x2);
    int t = min(a.y2,b.y2);
    int d = max(a.y1,b.y1);
    int ans = 0;
    if(l<r && d<t){
        ans = (r-l)*(t-d);
    }
    return ans;

}
int main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    rect a,b,c;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    cin >> c.x1 >> c.y1 >> c.x2 >> c.y2;
    int total = area(a) + area(b) - crossarea(a,c) - crossarea(b,c);
    cout << total;
    
}


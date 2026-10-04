#include "bits/stdc++.h"
//把糖都挂起来，奶牛按着顺序根据自己的身高走过去吃，奶牛吃多少长多少，如果
using namespace std;
const int N = 2e5 + 5;
long long a[N],b[N];
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int n,m;
    cin >> n >> m; //n头牛，m根拐杖
    for(int i=1;i<=n;i++){
        cin >> a[i]; //输入牛的array
    }
    for(int i=1;i<=m;i++){
        cin >> b[i];//输入candy的array
    }

    for(int i=1;i<=m;i++){ // 枚举的是candy
        long long now = 0; //当前吃了多少糖
        for(int j=1;j<=n;j++){ //枚举cow
            if(now == b[i]){ //当前吃了多少糖果的数量和奶牛高度的数量一样，说明奶牛全被吃掉了
                break;//停止循环
            }
            if(now < a[j]){
                long long t = min(a[j],b[i])-now;
                now += t,a[j] += t;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << a[i] << endl;
    }
    return 0;
}



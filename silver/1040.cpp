#include "bits/stdc++.h"

using namespace std;
pair<int, int> a[100001];
int minh[100001];
int maxh[100001];
int main(){
    freopen("moop.in", "r", stdin);
    freopen("moop.out", "w", stdout);
    int n;
    cin >> n;
    for(int i=1; i<=n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a+1,a+n+1); //pair默认的排序 first一样排second
    int cnt = 0;
    for(int i=1;i<=n;i++){
        cnt++; //记录有多少个连痛快数
        minh[cnt] = a[i].second;
        maxh[cnt] = a[i].second;
        while(cnt>1 && maxh[cnt] >= minh[cnt-1]){
            minh[cnt-1] = min(minh[cnt],minh[cnt-1]); //合并到前面那个
            maxh[cnt-1] = max(maxh[cnt], maxh[cnt-1]);
            cnt--; //删除了一个cnt要减少
        }
    }
    cout << cnt;
    return 0;
}
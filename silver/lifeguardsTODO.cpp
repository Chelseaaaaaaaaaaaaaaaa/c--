#include "bits/stdc++.h"
using namespace std;

struct Point {
    int t, id;  // ʱ���  ţ��Id
};
Point s[200001];

set<int> onduty;  // ��Ŀǰ�м�����ʼ�㣬���Ƕ�Ӧ�Ľ����㻹û����

int alone[100001];
int totalCover;

bool cmp(const Point &a, const Point &b) { 
    return a.t < b.t; 
}

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int st, en;
        cin >> st >> en;
        s[i] = {st, i};
        s[i + n] = {en, i};
    }
    sort(s, s + 2 * n, cmp);
    for (int i = 0; i < 2 * n; i++) {
        if(onduty.size()==1){
            alone[*onduty.begin()] += s[i].t-s[i-1].t;  //onduty.begin（）只是位置 *表示里面的内容
    }
        if(!onduty.empty()){
            totalCover += s[i].t-s[i-1].t;
        }

        if(onduty.count(s[i].id)>0){ //COUNT calculates how many times this id appear
            onduty.erase(s[i].id);
        }
        else{
            onduty.insert(s[i].id);
        }
    }
    int minAlone = INT_MAX;
    for (int i = 0; i < n; i++) {
        minAlone = min(minAlone, alone[i]);
    }
    cout << totalCover - minAlone << endl;

    return 0;
    
}

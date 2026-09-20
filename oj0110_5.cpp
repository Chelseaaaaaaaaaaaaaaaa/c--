#include "bits/stdc++.h"

using namespace std;
struct student{
    int number;
    int score;
};
student s[5001];

bool comp(const student &a, const student &b){
    if(a.score!=b.score){
        return a.score > b.score;
    }
    return a.number < b.number;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin >> s[i].number >> s[i].score;
    }
    sort(s,s+n,comp);
    m = m*1.5;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(s[i].score>=s[m-1].score){
            cnt++;
        }else{
            break;
        }

    }
    cout << s[cnt-1].score << " " << cnt << endl;
    for(int i=0;i<cnt;i++){
        cout << s[i].number << " " << s[i].score << endl;
    }
    
    return 0;
}
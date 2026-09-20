#include "bits/stdc++.h"

using namespace std;
struct student{
    int chinese;
    int total;
    int id
};
student s[301];

bool cmp(const student &a, const student &b){
    if(a.total != b.total){
        return a.total > b.total;
    }
    else if(a.chinese != b.chinese){
        return a.chinese > b.chinese;
    }
    return a.id<b.id;
}
int main(){
    int n,math,english;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s[i].chinese >> math >> english;
        s[i].total = s[i].chinese + math + english;
        s[i].id = i;
    }
    sort(s+1,s+n+1,cmp);
    for(int i=1;i<=5;i++){
        cout << s[i].id << " " << s[i].total << endl;
    }
    return 0;
}




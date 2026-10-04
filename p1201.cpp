#include "bits/stdc++.h"

using namespace std;
string name[11];
map<string,int> m;

int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> name[i];
    }
    string giver;
    int gift,num;
    for(int i=0;i<n;i++){
        cin >> giver >> gift >> num;
        if(num == 0){
            continue;
        }
        int average = gift/num;
        for(int i=0;i<num;i++){
            string name;
            cin >> name;
            m[name] += average;
        }

        m[giver] -= average * num;
    }
    for(int i=0;i<n;i++){
        cout << name[i] << ' ' << m[name[i]] << endl;
    }
    return 0;
}



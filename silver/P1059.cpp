#include "bits/stdc++.h"

using namespace std;
set<int> student;
int cnt[1001];
    int main(){
        // freopen("paint.in", "r", stdin);
        // freopen("paint.out", "w", stdout);
        ios::sync_with_stdio(false);
        cin.tie(0);
        int N;
        cin >> N;
        int ans = 0;
        for(int i=0;i<N;i++){
            int s;
            cin >> s;
            cnt[s]++;
            if(cnt[s] == 1){
                ans++;
            }
        }

        cout << ans << endl;
        for(int i=0;i<1001;i++){
            if(cnt[i]!=0){
                cout << i << " ";
            }
        }
//     for(int i=0;i<N;i++){
//         int s;
//         cin >> s;
//         student.insert(s);

//     }
    
//     cout << student.size() << endl;
//     for (auto &k : student) {
//         cout << k << " ";
//     }
//     return 0;
// }
    
}

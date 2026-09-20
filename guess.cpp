#include "bits/stdc++.h"

using namespace std;
struct ani{
    string name;
    int num;
    string chara[101];
};
int count(const ani&a, const ani&b){
    int cnt = 0;
    for(int i=0;i<a.num;i++){
        for(int j=0;j<b.num;j++){
            if(a.chara[i]==b.chara[j]){
                cnt++;
                break;
            }
        }
    }
    return cnt;
}
ani arr[101];
int main(){
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i].name >> arr[i].num;
        for(int j=0;j<arr[i].num;j++){
            cin >> arr[i].chara[j];
        }
    }
    int max_count=0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int cnt = count(arr[i],arr[j]);
            if(cnt>max_count){
                max_count = cnt;
            }
        }
    }
    cout << max_count+1;
    
    return 0;
}



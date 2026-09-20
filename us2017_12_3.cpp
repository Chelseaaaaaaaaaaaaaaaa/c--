#include "bits/stdc++.h"

using namespace std;
struct cow{
    int date;
    string name;
    int change;
};
cow arr[101];
bool comp(const cow &a, const cow &b){ //true不转换 false交换
    return a.date < b.date;
}
int main(){
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int N;
    cin >> N;
    int Bessie = 7;
    int Elsie = 7;
    int Mildred = 7;
    for(int i=0;i<N;i++){
        cin >> arr[i].date >> arr[i].name >> arr[i].change;
    }
    int cnt = 0;
    int large = INT_MIN;
    sort(arr,arr+N,comp);
    bool b1 = true;
    bool e1 = true;
    bool m1 = true;
    for(int i=0;i<N;i++){
        if(arr[i].name == "Bessie"){
            Bessie+=arr[i].change;
        }if(arr[i].name == "Elsie"){
            Elsie+=arr[i].change;
        }if(arr[i].name == "Mildred"){
            Mildred+=arr[i].change;
        }
        int num=0;
        num = max(Mildred,max(Bessie,Elsie));
        bool b2 = (num==Bessie);
        bool e2 = (num==Elsie);
        bool m2 = (num==Mildred);
        if(b2!=b1||e1!=e2||m1!=m2){
            cnt++;
        }
        b1=b2;
        e1=e2;
        m1=m2;
    }
    cout << cnt;
}



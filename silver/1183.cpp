#include "bits/stdc++.h"

using namespace std;
stack<int> st;
int arr[300001];
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }
    long long ans = 0;
    for(int i=1; i<=N;i++){
        while(st.size() > 0 && arr[i] >= arr[st.top()]){
            ans += i-st.top()+1;
            st.pop();
        }
        if(st.size()>0){
            ans += i-st.top()+1; 
        }
        st.push(i); //把i加进去 留给后面的pair配对
    }

    cout << ans;
    return 0;
}
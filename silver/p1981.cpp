#include "bits/stdc++.h"

using namespace std;
stack<int> st;
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    const int m = 10000;
    int a;
    cin >> a;
    st.push(a%m);
    char c;
    while(cin >> c >> a){ //反复的不断的读入
        if(c == '+'){
            st.push(a%m);
        }
        else if(c == '*'){
            int b = st.top();
            st.pop();
            st.push(((a%m)*b)%m);
        }
    }
    int ans = 0;

    while(!st.empty()){
        ans = (ans + st.top())%m;
        st.pop();
    }

    cout << ans;
    return 0;
}
#include "bits/stdc++.h"
using namespace std;
int n, a[100], b[100];
string t[100];

int main()
{
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    cin >> n;
    for (int i=0; i<n; i++) {
      cin >> t[i] >> a[i] >> b[i];
    }

    int start = 0, end=INT_MAX;
    bool ok = false;
    for (int i=n-1; i>=0; i--) {
        if ("none" == t[i]) {
            start = max(start, a[i]);
            end = min(end, b[i]);
            ok = true;
        }

        if (ok && "on" == t[i]) {
            start = max(start - b[i], 0);
            end -= a[i];
        }

        if (ok && "off" == t[i]) {
            start += a[i];
            end += b[i];
        }
    }

    cout<<start<<" "<<end<<endl;

    // TODO
    start = 0, end = INT_MAX;
    ok = false;
    for(int i=0;i<n;i++){
        if(t[i]=="none"){
            start = max(start,a[i]);
            end = min(end,b[i]);
            ok = true;
        }

        if(ok&& t[i]=="on"){
            start+= a[i];
            end += b[i];
        }
        if(ok && t[i]== "off"){
            start = max(0,start-b[i]);
            end -= a[i];
        }
    }
    cout<<start<<" "<<end;

    return 0;
}

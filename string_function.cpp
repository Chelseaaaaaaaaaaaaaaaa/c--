#include <bits/stdc++.h>
using namespace std;

/*
input
abcdabcd ab

output
0
4
XXXcdabcd
Xcd
*/
int main() {
    // find
    string s, b;
    cin >> s >> b;
    int pos = -1;
    // int pos = s.find(b);
    // int pos = s.rfind(b);
    while (s.find(b, pos + 1) != string::npos) {
        pos = s.find(b, pos + 1);
        cout << pos << endl;
    }

    if (s.find(b) == string::npos) {
        cout << "not found" << endl;
    } else {
        // replace
        startPos = s.find(b);
        // startPos, len, replacement content
        s.replace(startPos, b.length(), "XXX");
        cout << s << endl;
    }
    // s.erase(startPos, len);
    // s.substr(startPos, len)  // 不会对s造成改变
    cout << s.substr(2, 3) << endl;

    return 0;
}

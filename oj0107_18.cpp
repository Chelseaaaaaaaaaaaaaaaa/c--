#include <bits/stdc++.h>
///#include "macstdc++.h"
using namespace std;
int main(){
    string s1,s2;
    cin >> s1 >> s2;
    if(s1.length() < s2.length()){
        swap(s1,s2);
    }
    if(s1.find(s2)!=string::npos){
        cout << s2 << " is substring of " << s1;
    }else{
        cout << "No substring";
    }
}



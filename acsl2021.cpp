#include "bits/stdc++.h"

using namespace std;
string tento8(int b){
    string s = "";
    while(b>0){
        s = to_string(b%8) + s; //stoi(str),to_string(b%8)
        b /= 8;
    }
    return s;
}

int eightto10(string c){
    int snumber = 0;
    int base = 1;
    for(int i=c.length()-1;i>=0;i--){
        snumber += (c[i] - '0')* base;
        base*=8;
    }
    return snumber;
}

int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    string s,d;
    int r;
    cin >> s >> d >> r;
    int snumber = eightto10(s);
    int dnumber = eightto10(d);
    cout << snumber << endl<< dnumber << endl;
    int sum = 0;
    if(r==1){
        for(int k=0;k<s.length();k++){
            sum += s[k] - '0';
        }
        cout << sum;
        return 0;

    }else{
        for(int i=2;i<=r;i++){
            for(int j=1;j<=i;j++){
                snumber += dnumber;
                if(i==r){
                    s = tento8(snumber);
                    for(int k=0;k<s.length();k++){
                        sum += s[k] - '0';
                    }
                }
                
            }
        }

        cout << sum;
        return 0;
    }
}


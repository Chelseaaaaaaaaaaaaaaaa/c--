#include "bits/stdc++.h"

using namespace std;
int main(){
    int T,k;
    cin >> T >> k;
    for(int i=0;i<T;i++){
        int N;
        cin >> N;
        string s;
        cin >> s;
        if(N%2!=0){
            cout << -1 << endl;
            continue;
        }else{
            int half = N*3/2;
            for(int i=0;i<half;i++){
                string a = s.substr(i,3);
                string b = s.substr(i+half,3);
                //cout << "sub"<< a << " "<< b << endl;
                if(a==b){
                    s.replace(i,3,"111");
                    s.replace(i+half,3,"111");
                    //cout << "a=b" << s << endl;
                }else{
                    if(a=="COW"&&b=="OWC"){
                        s.replace(i,3,"122");
                        s.replace(i+half,3,"221");
                    }else if(a=="COW"&&b=="WCO"){
                        s.replace(i,3,"112");
                        s.replace(i+half,3,"211");
                    }else if(a=="OWC"&&b=="COW"){
                        s.replace(i,3,"112");
                        s.replace(i+half,3,"211");
                    }else if(a=="OWC"&&b=="WCO"){
                        s.replace(i,3,"122");
                        s.replace(i+half,3,"221");
                    }else if(a=="WCO"&&b=="OWC"){
                        s.replace(i,3,"112");
                        s.replace(i+half,3,"211");
                    }else if(a=="WCO"&&b=="COW"){
                        s.replace(i,3,"211");
                        s.replace(i+half,3,"112");
                    }
                }
            }
        }
        if(s.find("2")== string::npos){
            cout << 1 << endl;
        }else{
            cout << 2 << endl;
        }
        for(int i=0;i<=s.length()-2;i++){
            cout << s[i] << " ";
        }
        cout << s[s.length()-1] << endl;
    }
    return 0;
}



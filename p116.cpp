#include "bits/stdc++.h"

using namespace std;
vector<int> vec;
int main(){
    string s;
    int k;
    cin >> s >> k;
    vec.resize(s.length());
    for(int i=0;i<s.length();i++){
        vec[i] = s[i] -'0';
    }
    for(int i=0;i<k;i++){
        int j=0;
        while(j<vec.size()-1 && vec[j]<=vec[j+1]){
            j++; 
        }
        vec.erase(vec.begin()+j);
    }
    bool nonzero = false;
    for(int i=0;i<vec.size()-1;i++){ //最后一个需要输出
        if(vec[i]>0){
            nonzero = true;
        }
        if(nonzero){
            cout << vec[i];
        }
    } 
    cout << vec[vec.size()-1];

    /*
    string n;
    int k;
    cin >> n >> k;
    for(int i=0;i<k;i++){
        int len = n.length();
        bool deleted = 0;
        for(int i=0;i<len-1;i++){
            if(n[i]>n[i+1]){
                deleted =1;
                n.erase(i,1);
                break;
            }
        }
        if(!deleted){
            n.erase(len-1,1);
        }
    }
    int len = n.length();
    for(int i=0;i<len-1;i++){
        if(n[0]=='0'){
            n.erase(0,1);
        }else{
            break;
        }
    }
    cout<<n;
    
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    return 0;
    */

}






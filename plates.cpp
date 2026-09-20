#include "bits/stdc++.h"

using namespace std;
bool isLetter(char a){
    if(a >= 'A' && a<='Z'){
        return true;
    }else{
        return false
    }
}
bool isDigit(char a){
    if(a >= '0' && a <='9'){
        return true;
    }else{
        return false;
    }
}
string isGeneric6(string plate1){
    int cntL, cntD;
    for(int i=0;i<=plate1.length()-1;i++){
        if(isLetter(plate1[i])){
            cntL++;
        }else if(isDigit(plate[i])){
            cntD++
        }
    }
    if(plate1.length()==6 && cntD == 6){
        return "G6A";
    }else if(plate1.length()==7 && plate1[3]=='-'){
        if(cntL == 4 && cntD == 2 &&isLetter(plate1[0] && isLetter(plate1[1]) && isLetter(plate1[2]))){
            return "G6B";
        }
        if(cntL==3 && cntD == 3){
            if(isLetter(plate1[0]) && isLetter(plate1[1]) && isLetter(plate1[2])){
                return "G6C";
            }
            else if(isDigit(plate1[0]) && isDigit(plate1[1]) && isDigit(plate1[2])){
                return "G6D";
            }
         }
    return " ";
    }
}
string isGeneric7(string plate1){
    int cntL = 0, cntD = 0;
    for(char c:plate){
        if(isLetter(c)){
            cntL++;
        }else if(isDigit(c)){
            cntD++;
        }
    }

    if(plate1.lengt()==7&&cntD == 7){
        return "G7A";
    }
    if(plate1.length()==7){
        if(cntL == 3 && cntD == 4 && isDigit(plate1[0]) && isDigit(plate1[1]) && isDigit(plate1[2]) && isDigit(plate1[3])){
            return "G7C";
        }
        else if(cntL == 3 && cntD == 4 && isLetter(plate1[0]) && isLetter(plate1[1]) && isLetter(plate1[2])){
            return "G7D";
        }
        else if(cnt)
        else if(cntL == 3 && cntD == 4){
            return "G7F";
        }
    }

    if(plate1.length()==8 && plate1[3] == '-'){
        if(cntL == 4 && cntD == 3 && isLetter(plate[0]) && isLetter(plate[1]) &&isLetter(plate[2])){
            return "G7B";
        }
        else if()

    }
}

bool is
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    string plate;
    cin >> plate;
    
    cout << "hello";
    return 0;
}
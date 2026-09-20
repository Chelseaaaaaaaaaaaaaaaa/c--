#include "bits/stdc++.h"
#include <cstdio>

using namespace std;



/*
 * Complete the 'playGame' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING hand1
 *  2. STRING hand2
 *  3. STRING pile
 */
vector<string> p1;
vector<string> p2;
vector<string> draw;
string arr[8];
int transfer(char a){
    if(a=='A'){
        return 1;
    }
    if(a=='T'){
        return 10;
    }
    if(a=='J'){
        return 11;
    }
    
    if(a=='Q'){
        return 12;
    }
    
    if(a=='K'){
        return 13;
    }
    
    return a-'0';
}

char transferC(char a){
    if(a=='H'){
        a = 'r';
    }
    if(a=='D'){
        a = 'r';
    }
    if(a=='C'){
        a = 'b';
    }
    if(a == 'S'){
        a = 'b';
    }
    
    return a;
}
int direction = 0;

vector<string> split(const string& str){
    vector<string> tokens;
    istringstream input(str);
    string s;
    
    while(input >> s){
        tokens.push_back(s);
    }
    return tokens;
}



bool play(vector<string>& a){
    while(true){
        bool canContinue = false;
        for(int i=0;i<(int) a.size();i++){
            if(a[i][0] == 'K'){
                arr[direction*2+1] = a[i];
                direction++;
                canContinue = true;
                break;
            }else{
                bool haveCard = false;
                for(int j=0;j<8;j++){
                    if(transfer(arr[j][0])-transfer(a[i][0]) == 1 && transferC(arr[j][1]) != transferC(a[i][1])){
                        arr[j] = a[i];
                        haveCard = true;
                        canContinue = true;
                        a.erase(a.begin()+i);
                        break;
                    }
                }
                if(haveCard){
                    break;
                }
            }
        }
        if(!canContinue){
            break;
        }
        
    }
    
    
    if(draw.empty()){
        return false;
    }else{
        a.push_back(draw[0]);
        draw.erase(draw.begin());
        return true;
    }
    

}
string playGame(string hand1, string hand2, string pile) {
    p1 = split(hand1);
    for(int i=0;i<p1.size();i++){
        cout << p1[i]<< " ";
    } 
    cout << endl;
    p2 = split(hand2);
     for(int i=0;i<p2.size();i++){
        cout << p2[i]<< " ";
    } 
    cout << endl;
    draw = split(pile);
    for(int i=0;i<draw.size();i++){
        cout << draw[i] << " ";
    }
    
    for(int i=0;i<4;i++){
        arr[i*2]=draw[0];
        draw.erase(draw.begin());
        arr[i*2+1]= "E";
    }
   
   
    
    
    while(true){
        bool play_1 = play(p1);
        bool play_2 = play(p2);
        if(!play_1 && !play_2){
            break;
            
        }
    }
    
    string ans = "";
    for(int i=0;i<8;i++){
        ans += arr[i] + " ";
    }
    return ans;  
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string hand1;
    getline(cin, hand1);

    string hand2;
    getline(cin, hand2);

    string pile;
    getline(cin, pile);

    string result = playGame(hand1, hand2, pile);

    fout << result << "\n";

    fout.close();

    return 0;
}

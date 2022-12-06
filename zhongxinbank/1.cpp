#include <bits/stdc++.h>
using namespace std;

bool iseuler(char ch){
    if(ch == 'a' || ch == 'e' || ch == 'i' ||ch == 'o' ||ch == 'u'){
        return true;
    }
    if(ch == 'A' || ch == 'E' || ch == 'I' ||ch == 'O' ||ch == 'U'){
        return true;
    }
    return false;
}

int main(){
    string str;
    cin >> str;
    for(int i=0;i<str.size();i++){
        if(iseuler(str[i])){
            if(str[i] < 97){
                str[i] += 32;
            }
        }else{
            if(str[i] >= 97){
                str[i] -= 32;
            }
        }
    }
    cout << str << endl;
    return 0;
}
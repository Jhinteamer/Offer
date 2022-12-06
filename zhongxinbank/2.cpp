#include <bits/stdc++.h>
using namespace std;



int main(){
    string str;
    cin >> str;
    string str2 = "";
    unordered_map<char, int> hash;
    for(int i=0;i<str.size();i++){
        hash[str[i]]++;
        if(hash[str[i]] == 2){
            str2.push_back(str[i]);
        }
    }
    cout << str2 << endl;
    return 0;
}
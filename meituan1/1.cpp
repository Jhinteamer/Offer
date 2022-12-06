#include <bits/stdc++.h>
using namespace std;
void getnext(string& str, vector<int>& next){
    next[0] = -1;
    int i=0, j=-1;
    while(i < str.size()-1){
        if(j == -1 || str[i] == str[j] || str[i] == '*' || str[j] == '*'){
            i++;
            j++;
            next[i] = j;
        }
        else{
            j = next[j];
        }
    }

}
int kmp(string& str1, string& str2){
    int m = str1.size();
    int n = str2.size();
    vector<int> next(n);
    getnext(str2, next);
    int i=0;
    int j = 0;
    while(i < m && j < n){
        if(j == -1 || str1[i] == str2[j] || str2[j] == '*'){
            i++;
            j++;
        }
        else{
            j = next[j];
        }
    }
    if(j == n){
        return i - j;
    }
    else{
        return -1;
    }  
}
int get_kmp(string str1, string str2){
    int ans = 0;
    int cnt = 0;
    int real = kmp(str1, str2);
    while(real >= 0){
        ans++;
        str1 = str1.substr(real+1);
        real = kmp(str1, str2);
    }
    return ans;
}
int main(){
    int ii, jj;
    // cin >> ii >> jj;
    // string str1, str2;
    string str1 = "eqweqoiruqore";
    string str2 = "qor";
    // cin >> str1;
    // cin >> str2;
    cout << get_kmp(str1, str2) << endl;
    return 0;
}
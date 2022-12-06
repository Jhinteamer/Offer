#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> hashl = vector<vector<int>>(20);
vector<int> veclen = vector<int>(20);
vector<int> has_found = vector<int>(20);
void getnext(string& str, vector<int>& next){
    next[0] = -1;
    int i=0, j=-1;
    while(i < str.size()-1){
        if(j == -1 || str[i] == str[j]){
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
        if(j == -1 || str1[i] == str2[j]){
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
void get_kmp(string str1, string str2, int index){
    int real = kmp(str1, str2);
    int prev = 0;
    while(real >= 0){
        hashl[prev + real].push_back(index);
        // cout << prev + real << endl;
        prev = prev+real+1;
        str1 = str1.substr(real+1);
        real = kmp(str1, str2);
    }
}
void find_all(int m, int maxsize, int idx, int& ans){
    if(idx == maxsize){
        ans++;
        return;
    }
    for(auto & cur : hashl[idx]){
        if(has_found[cur] == 0){
            has_found[cur] = 1;
            find_all(m, maxsize, idx+veclen[cur], ans);
            has_found[cur] = 0;
        }
    }
}
int main(){
    int m, n;
    cin >> n >> m;
    string str1;
    cin >> str1;
    for(int i=0;i<m;i++){
        int kkk;
        cin >> kkk;
    }
    for(int i=0;i<m;i++){
        string ss;
        cin >> ss;
        veclen[i] = ss.size();
        get_kmp(str1, ss, i);
    }
    int ans = 0;
    find_all(m, str1.size(), 0, ans);
    cout << ans << endl;
    return 0;
}
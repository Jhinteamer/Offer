#include <bits/stdc++.h>
using namespace std;

int comp(string& str1, string& str2, int idx){
    int max_len = 0;
    if(idx >= 0){
        int cnt = 0;
        bool flag = false;
        for(int i=0;i<5-idx;i++){
            if(str1[i+idx] == str2[i]){
                if(flag == false){
                    cnt = 1;
                    flag = true;
                }else{
                    cnt++;
                }
            }else{
                if(flag == false){
                    continue;
                }else{
                    max_len = max(max_len, cnt);
                    cnt = 0;
                    flag = false;
                }
            }
        }
        max_len = max(max_len, cnt);
    }
    else{
        idx = -idx;
        int cnt = 0;
        bool flag = false;
        for(int i=0;i<5-idx;i++){
            if(str1[i] == str2[i+idx]){
                if(flag == false){
                    cnt = 1;
                    flag = true;
                }else{
                    cnt++;
                }
            }else{
                if(flag == false){
                    continue;
                }else{
                    max_len = max(max_len, cnt);
                    cnt = 0;
                    flag = false;
                }
            }
        }
        max_len = max(max_len, cnt);
    }
    return max_len;
}

int max_same(string str1, string str2){
    int max_len = 0;
    for(int i=-4;i<=4;i++){
        int cnt_len = 0;
        max_len = max(max_len, comp(str1, str2, i));
    }
    return max_len;
}
void operate_it(string& str1, string&str2, int& d){
    int len1 = str1.size();
    int len2 = str2.size();

    if(str1[0] == str2[0]){
        d += 2;
    }
    if(str1.substr(1, len1 - 6) == str2.substr(1, len2 - 6)){
        d += 3;
    }
    d += max_same(str1.substr(len1-5, 5), str2.substr(len2-5, 5));
    return ;
}
int main(){
    // string str1;
    // cin >> str1;
    // string str2;
    // cin >> str2;
    // cout << max_same(str1, str2) << endl;
    int d = 0;
    int n;
    cin >> n;
    int nn = n;
    while(nn--){
        string str1;
        cin >> str1;
        string str2;
        cin >> str2;
        operate_it(str1, str2, d);
    }
    printf("%.2f%\n", ((float(d) * 10) / float(n)));
    return 0;
}
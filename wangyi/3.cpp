#include <bits/stdc++.h>
using namespace std;
int find_max(string red_str){
    int cnt1 = 0, cnt2 = 0;
    int flag = 0;
    for(int i=0;i<red_str.size();i++){
        if(i % 2 == 0){
            if(flag == 0){
                if(red_str[i] != 'r'){
                    cnt1++;
                }
                flag = 1;
            }else{
                if(red_str[i] != 'd'){
                    cnt1++;
                }
                flag = 0;
            }
        }else{
            if(red_str[i] != 'e'){
                cnt1++;
            }
        }
    }
    flag = 0;
    for(int i=0;i<red_str.size();i++){
        if(i % 2 == 0){
            if(flag == 0){
                if(red_str[i] != 'd'){
                    cnt2++;
                }
                flag = 1;
            }else{
                if(red_str[i] != 'r'){
                    cnt2++;
                }
                flag = 0;
            }
        }else{
            if(red_str[i] != 'e'){
                cnt2++;
            }
        }
    }
    return min(cnt1, cnt2);
}
int main(){
    string red_str;
    cin >> red_str;
    int n = red_str.size();
    int max_e = (n-1) / 2;
    int cnt = 0;
    if(n % 2 == 1){
        cnt = find_max(red_str);
    }else{
        cnt = min(find_max(red_str.substr(0,n-1)), find_max(red_str.substr(1,n)));
    }
    cout << cnt << endl;
}
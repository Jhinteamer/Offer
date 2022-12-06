#include <bits/stdc++.h>
using namespace std;
int find_num(int cc){
    if(cc == 2){
            return 1;
        }else{
            return ((cc-1) / 2);
        }
}
int main(){
    char ch;
    // cout << str << endl;
    int flag = 0;
    vector<int> has;
    int cnt = 0;
    char p;
    char prev = 'z';
    int ans = 0;
    while(cin >> p){
        cout << p;
        if(p == '\n'){
            break;
        }
        if(flag == 0){
            if(prev != p){
                continue;
            }else{
                flag = 1;
                cnt = 2;
            }
        }else{
            if(prev != p){
                // has.push_back(cnt);
                ans += find_num(cnt);
                flag = 0;
            }else{
                cnt++;
            }
        }
        prev = p;
    }
    cout << ans << endl;
    return 0;
}
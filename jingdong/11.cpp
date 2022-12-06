#include <bits/stdc++.h>
using namespace std;
int main(){
    char str[200001];
    cin >> str;
    // cout << str << endl;
    bool flag = 0;
    vector<int> has;
    int cnt = 0;
    char p;
    for(int i=0;;i++){
        if(str[i] == '\0'){
            break;
        }
        if(flag == 0){
            if(str[i] != str[i+1]){
                continue;
            }else{
                flag = 1;
                cnt = 2;
            }
        }else{
            if(str[i] != str[i+1]){
                has.push_back(cnt);
                flag = 0;
            }else{
                cnt++;
            }
        }
        
    }
    if(flag == 1){
        has.push_back(cnt);
    }
    // for(int i=0;i<has.size();i++){
    //     cout << has[i];
    // }
    // cout << endl;
    int ans = 0;
    for(int i=0;i<has.size();i++){
        if(has[i] == 2){
            ans++;
        }else{
            ans += ((has[i]+1) / 3);
        }
    }
    cout << ans << endl;
    return 0;
}
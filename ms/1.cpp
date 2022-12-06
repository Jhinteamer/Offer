#include <bits/stdc++.h>
using namespace std;
int max(int a, int b){
    return a > b ? a : b;
}
int solution(string &S) {
    unordered_map<int,int> hash;
    hash[0] = -1;
    const int len = S.size();
    int cnt = 0;
    int max_len = 0;
    for(int i=0;i<len;i++){
        int cur = S[i] - 'a';
        if((cnt>>cur)%2==0){
            cnt += (1<<cur);
        }else{
            cnt -= (1<<cur);
        }
        if(hash.count(cnt) == 0){
            hash[cnt] = i;
        }else{
            max_len = max(max_len, i - hash[cnt]);
        }
    }
    return max_len;
}

int main(){
    string str;
    cin >> str;
    cout << solution(str) << endl;
}
// bdaaadadb
// abacb
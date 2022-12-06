#include <bits/stdc++.h>
using namespace std;


int main(){
    int a, b, k, v;
    string str;
    while(1){
        cin >> a >> b >> k >> v;
        // thing 表示可以放多少个隔间
        // k 一个最多隔多少个
        // b 带了多少个板子
        int thing = ((a-1) / v) + 1;
        int ans = 0;
        while(thing > 0){
            ans++;
            if(b >= k-1){
                thing -= k;
                b -= (k-1);
            }else{
                thing -= (b+1);
                b = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
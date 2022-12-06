#include <bits/stdc++.h>
using namespace std;

int main(){
    long long L, R;
    long long L1 = -1, R1 = -1;
    cin >> L >> R;
    if(L % 2 == 0){
        L1 = L;
        L++;
    }
    
    if(R % 2 == 1){
        R1 = R;
        R--;
    }
    long long ans = (R - L + 1) / 2;
    if(L1 > 0){
        long long cnt = 1;
        int flag = 0;
        while(L1 > cnt*2){
            cnt *= 2;
        }
        while(L1 > 2){
            while(L1 <= cnt){
                cnt /= 2;
            }
            L1 = L1 - cnt;
            flag++;
        }
        int aannss = ((L1 + flag) % 2);
        ans += aannss;
    }
    
    if(R1 > 0){
        long long cnt = 1;
        int flag = 0;
        while(R1 > cnt*2){
            cnt *= 2;
        }
        while(R1 > 2){
            while(R1 <= cnt){
                cnt /= 2;
            }
            R1 = R1 - cnt;
            flag++;
        }
        int aannss = ((R1 + flag) % 2);
        ans += aannss;
    }
    cout << ans << endl;
    return 0;
}
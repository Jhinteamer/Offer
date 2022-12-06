#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    int time2 = 0;
    while(n > 1 && n % 2 == 0){
        time2++;
        n = n / 2;
    }
    long long prev = 1, now = 2;
    int tt = 2;
    int has = 0;
    while(1){
        if(n == 1){
            has = 1;
            break;
        }else if(n == now){break;}
            else if(n < now){
            cout <<"-1"<<endl;
            return 0;
        }else{
            tt++;
            long long temp = now;
            now = now + prev;
            prev = temp;
        }
    }
    string str = "";
    while(time2--){
        str += "26";
    }
    if(has == 0){
        while(tt--){
        str += "1";
    }
    }
    
    cout << str << endl; 
    return 0;
}
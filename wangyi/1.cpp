#include <bits/stdc++.h>
using namespace std;
int cnt = 50;
queue<pair<int,int>> que;
int del_it(int a, int loc){
    int l = 1;
    loc--;
    while(loc--){
        l *= 10;
    }
    int remain = a % l;
    int remain2 = a % (l*10);
    a = a - remain2;
    a /= 10;
    a += remain;
    return a;
}
int get_count(int x){
    int i=0;
    while(x>0){
        i++;
        x /= 10;
    }
    return i;
}
void get_smallset(){
    int t = -1;
    while(!que.empty()){
        t++;
        int size = que.size();
        while(size--){
            int a = que.front().first;
            int b = que.front().second;
            que.pop();
            if(a % b == 0 || b % a == 0){
                cnt = min(cnt, t);
                return;
            }
            if(a == 0 || b == 0){
                return ;
            }
            int a_len = get_count(a);
            int b_len = get_count(b);
            for(int i=1;i<=a_len;i++){
                int aa = del_it(a, i);
                que.push(make_pair(aa, b));
            }
            for(int i=1;i<=b_len;i++){
                int bb = del_it(b, i);
                que.push(make_pair(a, bb));
            }
        }
    }
    return ;
}
int main(){
    // cout << get_count(3124124)<<endl;
    // cout << del_it(432342,6);
    int a, b;
    cin >> a >> b;
    que.push(make_pair(a, b));
    get_smallset();
    if(cnt == 50){
        cnt = -1;
    }
    cout << cnt << endl;
}
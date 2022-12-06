#include <bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator()(int a, int b){
        return op_cnt(a) < op_cnt(b);
    }
    int op_cnt(int a){
        int aa = a;
        int cnt = 0;
        while(aa > 0){
            cnt += (aa % 2);
            aa /= 2;
        }
        return a - cnt;
    }
};
int findtimes(int aa){
    int cnt = 0;
        while(aa > 0){
            cnt += (aa % 2);
            aa /= 2;
        }
        return cnt;
}
int main(){
    int n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, cmp> pq;
    for(int i=0;i<n;i++){
        int cc;
        cin >> cc;
        pq.push(cc);
    }
    while(k--){
        int cnt = pq.top();
        pq.pop();
        int newcnt = findtimes(cnt);
        pq.push(newcnt);
    }
    long long ans = 0;
    while(!pq.empty()){
        ans += (long long)pq.top();
        pq.pop();
    }
    cout << ans << endl;
    return 0;
}
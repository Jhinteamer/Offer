#include <bits/stdc++.h>
using namespace std;

int main(){
	priority_queue<int,vector<int>, greater<int>> pq_p, pq_q;
    
    int n, p, q;
    cin >> n >> p >> q;

    vector<vector<int>> from(n, vector<int>(3));
    for(int i=0;i<n;i++){
        int ii;
        cin >> ii;
        from[i][0] = ii;
    }
    for(int i=0;i<n;i++){
        int ii;
        cin >> ii;
        from[i][1] = ii;
    }
    for(int i=0;i<n;i++){
        int ii;
        cin >> ii;
        from[i][2] = ii;
    }
    sort(from.begin(), from.end(), [&](vector<int>& a, vector<int> b){
        return a[0] < b[0];
    });
    // for(int i=0;i<n;i++){
    //     cout << from[i][0]<< from[i][1]<< from[i][2]<<endl;
    // }
    int begin_idx = -1;
    int ans = 0;
    for(int i=0;i<n;i++){
        begin_idx = max(from[i][0], begin_idx);
        int end_idx = from[i][1];
        while(!pq_p.empty() && pq_p.top() < begin_idx){
            pq_p.pop();
        }
        while(!pq_q.empty() && pq_q.top() < begin_idx){
            pq_q.pop();
        }

        if(from[i][2] == 1){
            pq_p.push(end_idx);
        }else{
            pq_q.push(end_idx);
        }

        if(pq_p.size() >= p && pq_q.size() >= q){
            ans += min(pq_p.top(), pq_q.top()) - begin_idx + 1;
            begin_idx = min(pq_p.top(), pq_q.top()) + 1;
        }
    }
    cout << ans << endl;
	return 0;
}
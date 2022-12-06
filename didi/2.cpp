#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, p, q;
    cin >> n >> p >> q;
    vector<int> from(n);
    vector<int> to(n);
    vector<int> type_p(100000), type_q(100000);
    for(int i=0;i<n;i++){
        int ii;
        cin >> ii;
        from[i] = ii;
    }
    for(int i=0;i<n;i++){
        int ii;
        cin >> ii;
        to[i] = ii;
    }
    for(int i=0;i<n;i++){
        int type;
        cin >> type;
        if(type_p.size() <= to[i]){
            type_p.resize(to[i]+1);
            type_q.resize(to[i]+1);
        }
        if(type == 1){
            for(int j=from[i];j<=to[i];j++){
                type_p[j]++;
            }
        }else{
            for(int j=from[i];j<=to[i];j++){
                type_q[j]++;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<type_p.size();i++){
        if(type_p[i] >= p && type_q[i] >= q){
            ans++;
        }
    }
    cout << ans << endl;
	return 0;
}
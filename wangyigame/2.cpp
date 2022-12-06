#include <bits/stdc++.h>
using namespace std;

void calculate_it(vector<unordered_set<int>>& roads, int idx, int cnt_idx, bool flag){
    unordered_set<int>& this_set = roads[idx];
    unordered_set<int>& cnt_set = roads[cnt_idx];
    for(auto& it : cnt_set){
        if(!this_set.count(it)){
            this_set.insert(it);
            calculate_it(roads, idx, it, true);
        }
        if(flag == false){
            calculate_it(roads, idx, it, true);
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<unordered_set<int>> roads(n);
    unordered_map<int,int> hashmp;
    for(int i=0;i<n;i++){
        roads[i].insert(i);
        int p;
        cin >> p;
        for(int j=0;j<p;j++){
            int pp;
            cin >> pp;
            roads[i].insert(pp);
        }
    }
    for(int i=0;i<n;i++){
        calculate_it(roads, i, i, false);
        cout << roads[i].size() << "-----" << endl;
        for(auto& j : roads[i]){
            cout << " " << j;
        }
        cout << endl;
    }
    int ans = 0;
    for(int i=0;i<m;i++){
        int op, nod;
        cin >> op >> nod;
        if(op == 1){
            for(auto& it : roads[nod]){
                hashmp[it]++;
            }
            ans = max(ans, (int)hashmp.size());
        }else{
            for(auto& it : roads[nod]){
                hashmp[it]--;
                if(hashmp[it] == 0){
                    hashmp.erase(it);
                }
            }
        }
        cout << "----------------" << hashmp.size() << endl;
    }
    cout << ans << endl;

    return 0;
}
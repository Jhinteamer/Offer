#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> groups;
unordered_map<int, int> prev_size;
int main(){
    int n;
    cin >> n;
    vector<int> nums;
    int ans = 0;
    for(int i=0;i<n;i++){
        int ii;
        cin >> ii;
        nums.push_back(ii);
        if(groups.count(ii) > 0){
            int size = groups[ii].size();
            for(int j=0;j<size;j++){
                int prev = groups[ii][j];
                for(int k=prev+1;k<i;k++){
                    if(nums[k]<ii){
                        ans++;
                    }
                }
            }

        }
        else{
            groups[ii] = vector<int>(0);
        }
        groups[ii].push_back(i);
    }
    cout << ans << endl;
}
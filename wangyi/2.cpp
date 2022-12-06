#include <bits/stdc++.h>
using namespace std;
vector<long long> nums;
int main(){
    // cout << get_count(3124124)<<endl;
    // cout << del_it(432342,6);
    int n;
    cin >> n;
    nums.resize(n);
    long long odd = 0, dob = 0;
    for(int i=0;i<n;i++){
        long long cur;
        cin >> cur;
        nums[i] = cur;
        if(i % 2 == 0){
            dob = max(dob, cur);
        }else{
            odd = max(odd, cur);
        }
    }
    long long ans = 0;
    for(int i=0;i<n;i++){
        if(i % 2 == 0){
            ans += abs(dob-nums[i]);
        }
        else{
            ans += abs(odd-nums[i]);
        }
    }
4
    cout << ans << endl;
}
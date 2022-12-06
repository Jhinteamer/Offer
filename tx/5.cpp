#include <bits/stdc++.h>
using namespace std;

bool judge_idx(vector<int>& nums, vector<char>& nums2, int X, int Y, int idx, int cnt_num, int prevous){
    if(prevous == 0){
        nums[idx-1] == 'X';
    }else if(prevous == 1){
        nums[idx-1] == 'Y';
    }
    if(idx == nums.size()){
        return (cnt_num == 0);
    }
    else{
        return judge_idx(nums, nums2, X, Y, idx+1, cnt_num + X*(nums[idx]), 0) || 
            judge_idx(nums, nums2, X, Y, idx+1, cnt_num + Y*(nums[idx]), 1);
    }
}
bool judge_ok(vector<int>& nums, vector<char>& nums2, int X, int Y){
    return judge_idx(nums, nums2, X, Y, 0, 0, -1);
}
int main(){
    int n;
    int X, Y;
    cin >> n;
    vector<int> nums(n);
    vector<char> nums2(n);
    int sum_all = 0;
    for(int i=0;i<n;i++){
        int cc;
        cin >> cc;
        nums[i] = cc;
        sum_all += cc;
    }
    int s1 = sum_all / 2;
    int s2 = (sum_all + 1) / 2;
    while(s1 >= 0 && s2 >= 0){
        X = s1;
        Y = -s2;
        if(judge_ok(nums, nums2, X, Y)){
            break;
        }
        X = s2, Y = -s1;
        if(judge_ok(nums, nums2, X, Y)){
            break;
        }
        s1++;
        s2--;
    }
    cout << X << " " << Y << endl;
    for(int i=0;i<nums2.size();i++){
        cout << nums2[i];
    }
    cout << endl;
    return 0;
}
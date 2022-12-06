#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> nums;
    cin >> n;
    int nn = n;
    while(nn--){
        int cc;
        cin >> cc;
        nums.push_back(cc);
    }
    int st = 0, en = n-1;
    int flag = 0;
    while(st < en){
        if((nums[st] < nums[en] && flag == 0) || (nums[st] > nums[en] && flag == 1)){
            cout << nums[st] << " ";
            st++; 
        }else{
            cout << nums[en] << " ";
            en--;
        }
    }
    cout << nums[st] << endl;
    return 0;
}
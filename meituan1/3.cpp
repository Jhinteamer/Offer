#include <bits/stdc++.h>
using namespace std;
int is_pri[10000];
vector<int> nums;
void find_prime(int n){
    for(int i=2;i<n;i++){
        if(is_pri[i] == 0){
            if(i >= 7){
                nums.push_back(i);
            }
            for(int j=i;j<n;j+=i){
                is_pri[j] = 1;
            }
        }
    }
}
bool is_nn(int cnt){
    int i = 0;
    while(1){
        if(nums[i] > cnt){
            return false;
        }
        if(cnt % nums[i] == 0){
            return true;
        }
        i++;
    }
    return true;
}
int solu(int n){
    if(n < 5){
        return n;
    }
    n -= 5;
    int cnt = 6;
    while(n){
        if(!is_nn(cnt)){
            n--;
            if(n == 0){
                return cnt;
            }
        }
        cnt++;
    }
}
int main(){
    memset(is_pri, 0 ,sizeof(is_pri));
    find_prime(10000);
    int n;
    cin >> n;
    cout << solu(n) << endl;
    return 0;

}
#include <bits/stdc++.h>
using namespace std;

long long find_num(int n){
    long long remain = 1000000000 + 7;
    vector<vector<long long>> dp = vector<vector<long long>>(n+1, vector<long long>(3, 0));
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=2;j++){
            if(j == 0){
                dp[i][j] = dp[i-1][j];
            }
            if(j == 1){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % remain;
            }
            if(j == 2){
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j]) % remain;
            }        
        }
    }
    return dp[n][2];
}
int main(){
    int n;
    cin >> n;
    int odd = 0, dub = 0;
    for(int i=0;i<n;i++){
        int ss;
        cin >> ss;
        if(ss % 2 == 0){
            dub++;
        }else{
            odd++;
        }
    }
    // cout << dub << " " << odd << endl;
    long long ans = 0;
    ans += find_num(odd);
    ans += find_num(dub);
    cout << ans << endl;
    return 0;
}
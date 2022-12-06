#include <bits/stdc++.h>
using namespace std;

int getMinMovest(string s) {
 int ans = 0;
 vector<vector<int>> dp(s.size(), vector<int>(26, 0));
 char t = 'a';
    for(int i=0;i<26;i++){
        dp[0][i] = abs(s[0] - (t+i));
        dp[1][i]=abs(s[1]-(t+i))+abs(s[0]-(t+i));
    }

    // new
    for(int i=0;i<26;i++){
        dp[2][i] = dp[1][i] + abs(s[2] - (t+i));
    }
    // j start to 3


    for(int j=3;j<s.size();j++){
        int temp=s.size()*26;
        for(int i=0;i<26;i++){
            temp=min(dp[j-2][i],temp);
        }
        for(int i=0;i<26;i++){
        dp[j][i]=min(dp[j-1][i]+abs(s[j]-(t+i)),
                temp+abs(s[j]-(t+i))+abs(s[j-1]-t-i));
        }
    }
    ans=dp[s.size()-1][0];
    for(int i=1;i<26;i++){
        ans=min(ans,dp[s.size()-1][i]);
    }
    return ans;
}

int main(){
    // cout << getMinMovest("abab") << endl;
    char s[] = "Helloword";
    char b[] = "Helloword";
    // b = s;
    cout << b[0] << endl;
    return 0;
}
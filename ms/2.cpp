#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A, int M) {
    unordered_map<int, int> cnts;
    int ans = 0;
    for (int i = 0; i < A.size(); i++) {
        int num = ((A[i] % M) + M) % M;
        cnts[num]++;
        ans = max(ans, cnts[num]);
    }
    return ans;
}

int main()
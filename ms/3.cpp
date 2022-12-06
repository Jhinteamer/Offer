#include <bits/stdc++.h>
using namespace std;           

int solution(vector<int> &A, vector<int> &B) {
    int ans = 0;
    int N = A.size();
    int ans = INT_MAX;
    for(int i=0;i<N;i++){
        ans = min(ans, max(A[i], B[i]));
    }
    return ans;
}
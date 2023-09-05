
// C++ program to find no. of ways
// to fill a 3xn board with 2x1 dominoes.
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
 
int countWays(int n)
{
    int A[n + 1], B[n + 1];
    A[0] = 1, A[1] = 0, B[0] = 0, B[1] = 1;
    for (int i = 2; i <= n; i++) {
        A[i] = A[i - 2] + 2 * B[i - 1];
        B[i] = A[i - 1] + B[i - 2];
    }
 
    return A[n];
}

int solve(int A) {
    vector<vector<int>> dp(A+1,vector<int>(8,0));
    
    dp[0][7] = 1;
    
    for(int i = 1;i<=A;i++){
        dp[i][0] = dp[i-1][7];
        dp[i][1] = dp[i-1][6];
        // dp[i][2] = dp[i-1][5];
        dp[i][3] = (dp[i-1][4] + dp[i-1][7]) % MOD;
        dp[i][4] = dp[i-1][3];
        // dp[i][5] = dp[i-1][2];
        dp[i][6] = (dp[i-1][7] + dp[i-1][1]) % MOD;
        dp[i][7] = (dp[i-1][3] + dp[i-1][6] + dp[i-1][0])%MOD;
        
        // for(auto j:dp[i]) cout<<j<<" ";
        // cout<<"\n";
    }
    
    return dp[A][7];
    
}
 
int main()
{
    int n;
    cin>>n;
    cout << countWays(n);
    cout<<solve(n);
    return 0;
}
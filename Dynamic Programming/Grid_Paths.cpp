#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;

int32_t main(){
    int n;
    cin>>n;

    vector<vector<int>> mat(n,vector<int>(n));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            char c;
            cin>>c;

            if(c == '*')mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }

    vector<vector<int>> dp(n + 1,vector<int>(n+1,0));
    if(mat[0][0] == 1){
        cout<<0<<"\n";
        return 0;
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i == 1 && j == 1) dp[i][j] = 1;
            else if(mat[i-1][j-1] == 0){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD; 
            }
        }
    }
    cout<<(dp[n][n])%MOD<<"\n";
    return 0;
}
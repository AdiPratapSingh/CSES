#include "bits/stdc++.h"
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin>>n;
    int x;
    cin>>x;

    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> h(x+1,0);
    vector<vector<int>> dp(n,h);

    for(int i = 0;i<n;i++){
        dp[i][0] = 1;
        for(int j = 1;j <= x;j++){
            if(j >= v[i]){
                dp[i][j] = dp[i][j - v[i]];
            }
            if(i > 0)
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % (int)(1e9+7);
        }
    }

    cout<<dp[n-1][x] % (int)(1e9+7)<<"\n";
    return 0;
}
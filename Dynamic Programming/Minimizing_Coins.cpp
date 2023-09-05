#include "bits/stdc++.h"
#include <chrono>
using namespace std;
#define vi vector<int>
typedef vector<vector<long long>> vvl;
typedef vector<vector<pair<long long, long long>>> vvpl;
#define int long long
#define pb push_back
#define sz(x) (int)(x).size()
#define revsort(a, b) sort(a, b, greater<ll>())
#define all(x) (x).begin(),(x).end()
#define forn(i,n) for(int i=0;i<(n);i++)
#define dbg(x) cerr<<#x<<"->"<<(x)<<'\n';
#define prnt(x) cerr<<#x<<'{';for(auto T:x)cerr<<T<<' ';cerr<<"}\n";
#define present (container, element) (find(all(container), element) != container.end())

void solve();
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

void solve(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int> coins(n);
    for(auto &i:coins){
        cin>>i;
    }
    sort(all(coins));
    vector<int> dp(x+1,0);
    dp[0] = 0;
    // dp[n] = min( dp[n-1] + 1, dp[n-5] + 1, dp[n-7] + 1 )
    for(int i=1;i<x+1;i++){
        int c = 1000000007;
        for(int j=0;j<n&&(i-coins[j]>=0);j++){
            if(dp[i-coins[j]]<0){
                continue;
            }
            c = min(c,dp[i-coins[j]]+1);
        }
        if(c!=1000000007)
        dp[i] = c;
        else dp[i] = -1;
    }
    // prnt(dp);
    cout<<dp[x];

}
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
    int coins[n];
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    sort(coins,coins+n);
    vector<int> dp(x+1,0);
    dp[0] = 1;
    for(int i=1;i<x+1;i++){
        for(int j=0;j<n&&i-coins[j]>=0;j++){
            dp[i]+=dp[i-coins[j]];
        }
        dp[i]%=1000000007;
    }
    cout<<dp[x];
    // prnt(dp);
}
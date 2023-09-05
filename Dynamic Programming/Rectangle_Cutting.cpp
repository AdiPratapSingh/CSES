#include "bits/stdc++.h"
#define MOD 1000000007
using namespace std;
#define vi vector<int>
typedef vector<vector<long long>> vvl;
typedef vector<vector<pair<long long, long long>>> vvpl;
#define int long long
#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define revsort(a, b) sort(a, b, greater<ll>())
#define all(x) (x).begin(),(x).end()
#define forn(i,n) for(int i=0;i<(n);i++)
#define dbg(x) cerr<<#x<<"->"<<(x)<<'\n';
#define present (container, element) (find(all(container), element) != container.end())
template<class T,class V>void _print(map<T, V> v) {cerr<<" [ "; for(auto i:v) {_print(i);cerr<<" ";} cerr<<"]";}
#define dbg(x) cerr<<#x<<"->"<<(x)<<'\n';
#define pprnt(x) cerr<<#x<<'{';for(auto T:x)cerr<<"("<<T.first<<","<<T.second<<")"<<' ';cerr<<"}\n";
#define prnt(x) cerr<<#x<<'{';for(auto T:x)cerr<<T<<' ';cerr<<"}\n";
#define present (container, element) (find(all(container), element) != container.end())

int32_t main(){
    int n,m;
    cin>>n>>m;

    if(n>m) swap(n,m);

    int ans = 0;

    vector<vector<int>> dp(max(n,m)+1,vector<int>(max(m,n)+1,INT_MAX));

    for(int i = 1;i<=n;i++){
        for(int j = i;j<=m;j++){
            if(i == j){
                dp[i][j] = 0;
            }
            else{
                for(int k = 1;k<j;k++){
                    dp[i][j] = min(dp[i][j],dp[i][j-k] + dp[i][k] + 1);
                }
                for(int k = 0;k<i;k++){
                    dp[i][j] = min(dp[i][j],dp[i-k][j] + dp[k][j] + 1);
                }
                dp[j][i] = dp[i][j];
            }
        }
        // prnt(dp[i]);
    }

    cout<<dp[n][m]<<"\n";
}
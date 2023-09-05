#include "bits/stdc++.h"
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

    vector<int> cost(n);
    vector<int> pages(n);

    for(auto &i:cost)cin>>i;
    for(auto &i:pages)cin>>i;

    vector<int> dp(m+1,0);
    for(int i = 0;i<=n;i++){
        vector<int> prev = dp;
        for(int j = 0;j<=m;j++){
            if(i == 0 || j == 0){
                dp[j] = 0;
            }
            else if(cost[i-1] <= j){
                dp[j] = max(prev[j],prev[j-cost[i-1]] + pages[i-1]);
            }
        }
    }

    cout<<dp[m]<<"\n";
    return 0;
}
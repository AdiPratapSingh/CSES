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
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i]; 
    }

    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    for(int j = 0;j < n;j++){
        for(int i = j;i >= 0;i--){
            if((j-i) == 1){
                dp[i][j] = max(a[i],a[j]);
            }
            else if(i == j){
                dp[i][j] = a[i];
            }
            else{
                dp[i][j] = max(a[i] + min(dp[i+2][j],dp[i+1][j-1]),a[j] + min(dp[i+1][j-1],dp[i][j-2]));
            }
        }
    }

    cout<<dp[0][n-1]<<"\n";
}
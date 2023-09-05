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

    vector<int> a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
        if(i>0 && a[i]!=0 && a[i-1]!=0){
            if(abs(a[i] - a[i-1]) > 1){
                cout<<"0\n";
                return 0;
            }
        }
    }

    vector<vector<int>> dp(m+2,vector<int>(n,0));
    int flag = 0;

    if(a[0] == 0){
        flag = 1;
        for(int i = 1;i<m+1;i++){
            dp[i][0] = 1;
        }
    }
    else{
        dp[a[0]][0] = 1;
    }

    int ans = 1;

    for(int j = 1;j<n;j++){
        if(a[j] != 0){
            if(flag == 1){
                ans = (ans * (dp[a[j]][j-1] + dp[a[j] + 1][j-1] + dp[a[j] - 1][j-1])) % MOD;
            }
            dp[a[j]][j] = 1;
        }
        else{
            flag = 1;
            for(int i = 1;i<m+1;i++){
                dp[i][j] = (dp[i][j-1] + dp[i+1][j-1] + dp[i-1][j-1])%MOD;
            }
        }
    }


    if(a[n-1] == 0){
        int mul = 0;
        for(int i = 0;i<m+2;i++){
            mul = (mul + dp[i][n-1])%MOD;
        }
        ans = (ans * mul)%MOD;
    }
    cout<<ans<<"\n";
}
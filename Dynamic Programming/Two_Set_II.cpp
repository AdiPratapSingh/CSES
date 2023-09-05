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

ll power(ll a,ll p){
    int ans = 1;

    if(p == 0) return 1;

    while(p > 0){
        if(p%2){
            ans = (ans*a)%MOD;
        }
        p = p/2;
        a = (a*a)%MOD;
    }

    return ans;
}

int32_t main(){
    int n;
    cin>>n;

    vector<int> a(n);
    int sum = 0;
    for(int i = 0;i<n;i++){
        a[i] = i+1;
        sum += a[i];
    }

    if(sum%2){
        cout<<"0\n";
        return 0;
    }
    sum/=2;

    vector<int> dp(sum+1,0);
    vector<int> prev = dp;

    prev[0] = 1;

    for(int i = 0;i < n;i++){
        for(int j = 0;j<=sum;j++){
            if(j >= a[i]){
                dp[j] = ((prev[j - a[i]] + prev[j]))%MOD;
            }
            else{
                dp[j] = prev[j];
            }
        }
        prev = dp;
    }

    cout<<(dp[sum]*power(2,MOD-2))%MOD<<"\n";
}
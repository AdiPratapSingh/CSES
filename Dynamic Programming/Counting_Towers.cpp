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
    int t;
    cin>>t;

    vector<int> comb(1000001,0);
    vector<int> split(1000001,0);
    
    comb[1] = 1;
    split[1] = 1;

    for(int i = 2;i<1000001;i++){
        comb[i] = (2*comb[i-1] + split[i-1])%MOD;
        split[i] = (4*split[i-1] + comb[i-1])%MOD;
    }

    while(t--){
        int h;
        cin>>h;

        cout<<(comb[h] + split[h]) % MOD<<"\n";
    }

    return 0;
}
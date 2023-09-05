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
    for(auto &i:a)cin>>i;

    vector<int> inc;
    inc.pb(a[0]);
    for(int i = 1;i<n;i++){
        auto it = upper_bound(inc.begin(),inc.end(),a[i]);
        
        if(inc[inc.size() - 1] < a[i]){
            inc.pb(a[i]);
        }
        else if(it != inc.end() && a[i] != *(it - 1)){
            *it = a[i];
        }
    }

    cout<<inc.size()<<"\n";
}
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

static bool comp(vector<int> &a,vector<int> &b){
    return a[1] < b[1];
}

int32_t main(){
    int n;
    cin>>n;

    vector<vector<int>> list(n,vi(3));
    vector<int> ft;

    for(int i = 0;i<n;i++){
        cin>>list[i][0]>>list[i][1]>>list[i][2];
    }

    sort(list.begin(),list.end(),comp);
    for(int i = 0;i<list.size();i++){
        ft.pb(list[i][1]);
    }

    vector<int> a(n);

    a[0] = list[0][2];
    for(int i = 1;i<n;i++){
        a[i] = max(a[i-1],list[i][2]);
        auto it = lower_bound(ft.begin(),ft.end(),list[i][0]);
        int idx = it - ft.begin();

        if(list[idx][1] < list[i][0]){
            a[i] = max(a[i],a[0] + list[i][2]);
        }
        else if(idx > 0 && list[idx-1][1] < list[i][0]){
            a[i] = max(a[i],a[idx-1] + list[i][2]);
        }
    }

    cout<<a[n-1]<<"\n";
}
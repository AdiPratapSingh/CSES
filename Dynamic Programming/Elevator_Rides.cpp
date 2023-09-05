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
    int n,x;
    cin>>n>>x;

    vector<int> a(n);
    for(auto &i:a)cin>>i;

    vector<int> lift(1<<n + 1,INT_MAX);
    vector<int> last(1<<n + 1,0);

    lift[0] = 0;
    last[0] = x;

    for(int i = 0;i < (1 << n);i++){
        for(int j = 0;j<20;j++){
            if(((1<<j) & i)>>j){
                // hold.pb(a[j]);

                int h1 = lift[((1<<j) ^ i)];
                int h2 = last[((1<<j) ^ i)];

                if(h2 + a[j] > x){
                    if(h1 + 1 < lift[i] || (lift[i] == h1 + 1 && a[j] < last[i]) ){
                        lift[i] = h1 + 1;
                        last[i] = a[j];
                    }
                }
                else{
                    if(h1 < lift[i] || ( h1 == lift[i] && a[j] + h2 < last[i] )){
                        lift[i] = h1;
                        last[i] = a[j] + h2;
                    }
                }
            }
        }
    }

    cout << lift[(1<<n) - 1] << "\n";
}
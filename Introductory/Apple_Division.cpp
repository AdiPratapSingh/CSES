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
    vector<int> apple(n);int total = 0;
    for(auto &i:apple)cin>>i,total+=i;
    sort(all(apple));                      
    int i=n-1;int tar = ceil(total/2);  dbg(total);    
    // while(i>=0){    dbg(apple[i]);
    //     if(t >= apple[i]){
    //         t -= apple[i];                  // dbg(t);
    //     }
    //     i--;
    // }
    int t = 1000000000;


    for(int i=1;i<(1ll<<n);i++){
        int curr = 0;
        for(int j=1,k=0;j<(1ll<<n);j=j*2,k++){
            if(j&i){
                curr+=apple[k];
            }
            // dbg(curr);
        }
        // dbg(t);
        if(tar<=curr)
        t = min(t,abs(curr - tar));
        // dbg(curr);
    }

    if(total%2&&!t)cout<<1;
    else if(total%2==0) cout<<t*2;
    else cout<<(2*t - 1);
}
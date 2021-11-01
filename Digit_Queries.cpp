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
    int t;
    cin >> t;
    while(t--)solve();
}

int power(int a,int b){
    int ans = 1;
    while(b){
        if(b%2){
            ans = ans*a;
        }
        a = a*a;
        b=b/2;
    }
    return ans;
}

void solve(){
    int p;
    cin>>p;
    int curr = 0;
    int i = 1;
    int l = 1;
    while(curr + l*i*9<=p){
        curr = curr + l*i*9;
        i=i*10;
        l++;
    }dbg(curr);dbg(i);
    int ans = i - 1 + ceill((long double)(p - curr)/l);dbg(l);
    int n = (p-curr)%l;
    dbg(ans);
    dbg(n);
    if(n==0){
        cout<<(ans%10)<<"\n";
    }
    else{
        cout<<((ans/power(10,l-n))%10)<<"\n";
    }
}

#include <stdio.h>
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define forn(i,n) for(int i=0;i<(n);i++)
#define dbg(x) cerr<<#x<<"->"<<(x)<<'\n';
#define prnt(x) cerr<<#x<<'{';for(auto T:x)cerr<<T<<' ';cerr<<"}\n";
using namespace std;

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    int a,b;
    int h;
    while(t--){
        cin>>a>>b;
        h = (a+b)/3;
        if((a+b)%3==0&&a>=h&&b>=h){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}

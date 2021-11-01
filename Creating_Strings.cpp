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

set<string> ans;

void permute(string a, int l, int r)
{
    // Base case
    if (l == r){
        ans.insert(a);
    }
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++){            
            if(a[i]==a[l]&&l!=i) continue;
            swap(a[l], a[i]);
            permute(a, l+1, r);
            swap(a[l], a[i]);
        }
    }
}
 
// Driver Code
int32_t main()
{   
    cin.tie(0)->sync_with_stdio(0);
    string str;
    cin >> str;
    sort(all(str));
    int n = str.size();
    permute(str, 0, n-1);
    cout<<ans.size()<<"\n";
    vector<string> s;
    for(auto i:ans)s.push_back(i);
    sort(all(s));
    for(auto i:s)cout<<i<<"\n";
    return 0;
}

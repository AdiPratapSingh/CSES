#include <bits/stdc++.h>
// #define int long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define forn(i,n) for(int i=0;i<(n);i++)
#define dbg(x) cerr<<#x<<"->"<<(x)<<'\n';
#define prnt(x) cerr<<#x<<'{';for(auto T:x)cerr<<T<<' ';cerr<<"}\n";
using namespace std;

// void solve(int t){
//     if(t==0){
//         for(int i=0;i<ans.size();i++){
//             printf("%lld",ans[i]);
//         }
//         printf("\n");
//         return;
//     }
//     ans.push_back(0);
//     // cout<<t<<endl;
//     solve(t-1);
//     ans.pop_back();
//     ans.push_back(1);
//     // cout<<t<<endl;
//     solve(t-1);
//     ans.pop_back();
//     return;
// }

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    vector<int> ans(t,0);
    vector<vector<int>> list((1<<t),ans);
    list[0][0]=0;
    list[1][0]=1;
    int count = 1;
    //solve(t,ans);
    for(int i=1;i<t;i++){
        int c = 1ll<<i;
        for(int j=1;j<=c;j++){
            list[count+j]=list[count-j+1];
            list[count+j][i]=1;
        }
        count+=c;
    }
    for(int i=0;i<list.size();i++){
        for(int j=0;j<list[i].size();j++){
            cout<<list[i][j];
        }
        cout<<endl;
    }
    return 0;
}

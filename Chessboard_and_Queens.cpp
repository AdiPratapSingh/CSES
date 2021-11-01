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
#define pprnt(x) cerr<<#x<<'{';for(auto T:x)cerr<<"("<<T.first<<","<<T.second<<")"<<' ';cerr<<"}\n";
#define present (container, element) (find(all(container), element) != container.end())

void solve();
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

int check(int x, vector<pair<int,int>> &loc){
    int flag = 0;
    for(int i=0;i<loc.size();i++){
        if(x==loc[i].first){
            flag = 1;
            break;
        }
    }
    if(flag) return 0;
    else return 1;
}

void solve(){
    vector<pair<char,bool>> list(8);
    vector<vector<pair<char,bool>>> mat(8,list);

    vector<int>add;
    vector<int>sub;
    vector<pair<int,int>>loc;
    
    string s;
    for(auto &i:mat){
        cin>>s;
        for(int j=0;j<8;j++){
            i[j].first = s[j];
            if(i[j].first=='.')
            i[j].second = true;
            else i[j].second = false;
        }
    }

    int ans = 0;
    int count = 0;
    int x=0,y=0;
    while(1){
        if(mat[y][x].second&&find(all(add),x+y)==add.end()&&find(all(sub),x-y)==sub.end()&&check(x,loc)){
            add.push_back(x+y);
            sub.push_back(x-y);
            loc.push_back(make_pair(x,y));
            pprnt(loc);
            count++;
            y = y + 1;
            x=-1;
        }
        x++;
        if(x==8 && y==0) break;
        if(x>=8){
            x=0;
            y++;
        }
        if(count==8){
            ans++;
            add.pop_back();
            sub.pop_back();
            x = loc.back().first + 1;
            y = loc.back().second;
            loc.pop_back();
            pprnt(loc);
            count--;
            if(x==8){
                x=0;
                y++;
            }
        }   
        if(y>count){
            add.pop_back();
            sub.pop_back();
            x = loc.back().first + 1;
            y = loc.back().second;
            loc.pop_back();
            pprnt(loc);
            count--;
            if(x==8 && y==0) break;
            if(x==8){
                x=0;
                y++;
            }
        }
    }
    cout<<ans;
}
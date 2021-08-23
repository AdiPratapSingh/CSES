#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define forn(i,n) for(int i=0;i<(n);i++)
#define dbg(x) cerr<<#x<<"->"<<(x)<<'\n';
#define prnt(x) cerr<<#x<<'{';for(auto T:x)cerr<<T<<' ';cerr<<"}\n";
using namespace std;

void solve(){
    vector<pair<int,char>> list;
    char c;
    string s;
    getline(cin,s);
    int flag = 0;
    int index = 0;
    int it_is=0;
    // cout<<s.size()<<endl;
    for(int i=0;i<s.size();i++){
        c=s[i];
        for(int j=0;j<list.size();j++){
            if(list[j].second==c){
                list[j].first++;//cout<<"!!!"<<list[j].first<<"!!!"<<endl;
                flag=1;
                break;
            }
        }
        if(!flag){
            list.push_back(make_pair(1,c));
            index++;
            // cout<<"***"<<index<<"***"<<endl;
        }
        flag = 0;
    }
    for(int i=0;i<list.size();i++){
        if(list[i].first%2){
            if(it_is){   
                cout<<"NO SOLUTION";
                return;
            }
            it_is = 1;
            flag = i;
        }
    }
    for(int i=0;i<list.size();i++){
        if(i==flag) continue;
        for(int j=0;j<list[i].first/2;j++){
            cout<<list[i].second;
        }
    }
    for(int i=0;i<list[flag].first;i++){
        cout<<list[flag].second;
    }
    for(int i=0;i<list.size();i++){
        if(list.size()-1-i==flag) continue;
        for(int j=0;j<list[list.size()-1-i].first/2;j++){
            cout<<list[list.size()-1-i].second;
        }
    }
    cout<<endl;
    list.clear();
    s.clear();
    return;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}

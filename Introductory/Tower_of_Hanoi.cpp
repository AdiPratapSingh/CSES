#include <bits/stdc++.h>
// #define int long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define forn(i,n) for(int i=0;i<(n);i++)
#define dbg(x) cerr<<#x<<"->"<<(x)<<'\n';
#define prnt(x) cerr<<#x<<'{';for(auto T:x)cerr<<T<<' ';cerr<<"}\n";
using namespace std;

int p = 0;

// moves two elements from first to third
// void move2(stack<int>&first,stack<int>&third,stack<int>&second){
//     int a = first.top();
//     first.pop();
//     third.push(a);
//     a=first.top();
//     first.pop();
//     second.push(a);
//     a=third.top();
//     third.pop();
//     second.push(a);
//     return;
// }
// void dis2(stack<int> &first,stack<int> &second,stack<int> &third){
    
// }
vector<int>source,destination;
void towerOfHanoi(stack<int> &first,stack<int> &second,stack<int> &third,int n,int from,int to){ // 2 -> 3  2->1
    int hold;
    if(n==1){
        int a = first.top();
        p++;
        source.push_back(from);
        destination.push_back(to);
        // prnt(source);
        // prnt(destination);
        // cout<<from<<" fir "<<to<<endl;
        first.pop();
        third.push(a);
        return;
    }
    hold = (to + from)%4==0?2:(to + from)%4; //cout<<"to = "<<to<<" from = "<<from<<" hold = "<<hold<<" n = "<<n<<endl;
    towerOfHanoi(first,third,second,n-1,from,hold);
    int a = first.top();
    first.pop();
    third.push(a);
    p++;
    source.push_back(from);
    destination.push_back(to);
    // prnt(source);
    // prnt(destination);
    // cout<<from<<" sec "<<to<<" "<<n<<" "<<hold<<endl;
    towerOfHanoi(second,first,third,n-1,hold,to);
    return;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    stack<int> first;
    stack<int> second;
    stack<int> third;
    for(int i=0;i<t;i++){
        first.push(t-i);
    }
    towerOfHanoi(first,second,third,t,1,3);
    cout<<p<<endl;
    for(int i=0;i<p;i++){
        cout<<source[i]<<" "<<destination[i]<<endl;
    }
    source.clear();
    destination.clear();
    return 0;
}

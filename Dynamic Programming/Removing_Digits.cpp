#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> a(n+1,1000000);
    string s;

    for(int i = 0;i <= n; i++){
        if(i < 10){
            a[i] = 1;
        }
        else{
            s = to_string(i);
            int m = INT_MAX;
            for(int j = 0; j < s.size(); j++){
                m = min(m,a[i-(s[j]-'0')] + 1);
            }
            a[i] = m;
        }
        // cout<<i<<" "<<a[i]<<"\n";
    }

    cout<<a[n]<<"\n";
}
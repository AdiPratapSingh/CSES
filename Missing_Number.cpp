#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
int h;

int main(){
    int n;
    scanf("%d",&n);
    set <int> v;
    for(int i=1;i<n;i++){
        scanf("%d",&h);
        v.insert(h);
    }
    set<int> :: iterator itr = v.begin();
    for(int i=1;i<=n;i++,itr++){
        if((*itr)!=i){
            cout<<i;
            break;
        }
    }
    return 0;
}
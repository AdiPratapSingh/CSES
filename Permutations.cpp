#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    if(n<4&&n!=1){
        cout<<"NO SOLUTION";
        return 0;
    }
    for(int i=1;2*i<=n;i++){
        cout<<2*i<<" ";
    }
    for(int i=0;2*i+1<=n;i++){
        cout<<2*i+1<<" ";
    }
    return 0;
}
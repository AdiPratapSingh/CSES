#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int ans = 1;
    for(int i=0;i<n;i++)
    ans=(ans*2)%1000000007;
    cout<<ans;
}
#include <bits/stdc++.h>
#include <stdio.h> 
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    scanf("%lld", &n);
    printf("%lld ",n);
    while(n!=1){
        if(n%2){
            n = 3*n + 1;
        }
        else{
            n = n/2;
        }
        printf("%lld ",n);
    }
    return 0;
}
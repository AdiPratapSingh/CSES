#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    scanf("%d", &n);
    long long curr;
    long long prev;
    scanf("%lld",&prev);
    long long count = 0;
    n--;
    while(n--){
        scanf("%lld",&curr);
        if(curr<prev){
            count=count+prev-curr;
            curr=prev;
        }
        prev=curr;
    }
    printf("%lld",count);
    return 0;
}
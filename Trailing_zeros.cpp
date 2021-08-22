#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int count = 0;
    int div = 5;
    while(n/div>0){
        count+=n/div;
        div*=5;
    }
    printf("%d",count);
}
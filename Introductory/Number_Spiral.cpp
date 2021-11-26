#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>> t;
    while (t--){
        long long x;
        long long y;
        scanf("%lld %lld",&y,&x);
        if(x==y){
            cout<<(x-1)*(x-1)+x<<endl;
        }
        else if(x>y){
            if(x%2){
                cout<<x*x -y +1<<endl;
            }
            else{
                cout<<(x-1)*(x-1)+y<<endl;
            }
        }
        else if(y>x){
            if(y%2){
                cout<<(y-1)*(y-1)+x<<endl;
            }
            else{
                cout<<y*y - x +1<<endl;
            }
        }
    }
    return 0;
}
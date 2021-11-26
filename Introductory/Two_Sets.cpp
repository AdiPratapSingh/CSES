#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n%4==1||n%4==2){
        cout<<"NO";
    }
    else if(n%4==0){
        cout<<"YES"<<endl;
        cout<<n/2<<endl;
        for(int i=1;i<=n;i=i+4){
            cout<<i<<" "<<i+3<<" ";
        }
        cout<<"\n"<<n/2<<endl;
        for(int i=2;i<=n;i=i+4){
            cout<<i<<" "<<i+1<<" ";
        }
        cout<<endl;
    }
    else if(n%4==3){
        cout<<"YES"<<endl;
        if(n%8==3){
            cout<<(n+1)/2<<endl;
            for(int i=1;i<=n;i=i+4){
                if(i!=n-2)
                cout<<i<<" "<<i+3<<" ";
                else
                cout<<i<<" "<<(n+1)/2<<endl;
            }
            cout<<n/2<<endl;
            for(int i=2;i<=n;i=i+4){
                if(i!=(n+1)/2)
                cout<<i<<" "<<i+1<<" ";
                else{
                    cout<<i+1<<" ";
                }
            }
            cout<<endl;
        }
        else{
            cout<<(n+1)/2<<"\n"<<2<<" "<<4<<" ";
            for(int i=5;i<=n;i=i+4){
                if(i!=n-2)
                cout<<i<<" "<<i+3<<" ";
                else
                cout<<i<<" "<<(n-1)/2<<endl;
            }
            cout<<n/2<<"\n"<<1<<" ";
            for(int i=6;i<=n;i=i+4){
                if(i!=(n+1)/2 -2)
                cout<<i<<" "<<i+1<<" ";
                else{
                    cout<<i<<" "<<3<<" ";
                }
            }
        }
    }
    return 0;
}
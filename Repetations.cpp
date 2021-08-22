#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int count=1;
    int max=1;
    string word;
    cin >> word;
    int size = word.size();
    while(size--){
        if(word[size] == word[size - 1]){
            count++;
        }
        else{
            max=max>count?max:count;
            count =1;
        }
    }
    max=max>count?max:count;
    cout<<max;
    return 0;
}
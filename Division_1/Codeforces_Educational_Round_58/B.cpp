#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
//PROBLEM LINK
//https://codeforces.com/contest/1101/problem/B

int main(){
    string str;
    cin>>str;
    ll n = str.length();
    
    ll l = -1, r = -1;
    
    for(int i = 0; i < n; i++){
        if(str[i] == '['){
            l = i;
            break;
        }
    }
    
    for(int i = n-1; i >= 0; i--){
        if(str[i] == ']'){
            r = i;
            break;
        }
    }
    
    if(l == -1 || r == -1){
        cout<<"-1\n";
        return 0;
    }
    if(l >= r){
        cout<<"-1\n";
        return 0;
    }
    
    //cout<<"l: "<<l<<"   r: "<<r<<endl;
    ll x = -1, y = -1;
    for(int i = l; i <= r; i++){
        if(str[i] == ':'){
            x = i;
            break;
        }
    }
    
    for(int i = r; i >= l; i--){
        if(str[i] == ':'){
            y = i;
            break;
        }
    }
    
    if(x == -1 || y == -1 || x == y){
        cout<<"-1\n";
        return 0;
    }
    
    ll ans = 4;
    for(int i = x; i <= y; i++){
        if(str[i] == '|')
            ans++;
    }
    
    cout<<ans<<endl;
    
    
    return 0;
}
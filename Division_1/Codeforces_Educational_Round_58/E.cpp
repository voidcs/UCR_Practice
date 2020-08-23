#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://codeforces.com/contest/1101/problem/E

int main(){
    ll t;
    scanf("%lld", &t);
    ll minH = -1, minW = -1;
    while(t--){
        //cout<<"minH: "<<minH<<"   minW: "<<minW<<endl;
        char c;
        scanf(" %c", &c);
        //cout<<"c: "<<c<<endl;
        if(c == '+'){
            ll x, y;
            scanf("%lld%lld", &x, &y);
            if(x > y)
                swap(x, y);
            minH = max(minH, x);
            minW = max(minW, y);
        }
        else{
            ll x, y;
            scanf("%lld%lld", &x, &y);
            if(x > y)
                swap(x, y);
            if(minH <= x && minW <= y)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    
    return 0;
}

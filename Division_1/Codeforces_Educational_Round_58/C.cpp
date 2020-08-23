#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
//PROBLEM LINK
//https://codeforces.com/contest/1101/problem/C

struct seg{
    ll l;
    ll r;
    ll index;
    ll group;
};

bool comp(seg x, seg y){
    return x.index < y.index;
}

bool comp2(seg x, seg y){
    if(x.l != y.l)
        return x.l < y.l;
    else
        return x.r < y.r;
}
 
int main(){
    ll t;
    scanf("%lld", &t);
    while(t--){
        ll n;
        scanf("%lld", &n);
        seg a[n];
        for(int i = 0; i < n; i++){
            ll x, y;
            scanf("%lld%lld", &x, &y);
            a[i].l = x;
            a[i].r = y;
            a[i].index = i;
            a[i].group = 0;
        }
        
        sort(a, a + n, comp2);
//        for(int i = 0; i < n; i++){
//            cout<<a[i].first.first<<" "<<a[i].first.second<<endl;
//        }
        
        vector<pair<ll, ll>> v;
        a[0].group = 1;
        v.push_back({a[0].l, a[0].r});
        
        bool flag = 0;
        for(int i = 1; i < n; i++){
            //cout<<"V.FIRST: "<<v.back().first<<"   V.SECOND: "<<v.back().second<<endl;
            if(flag){
                a[i].group = 2;
                continue;
            }
            if(a[i].l <= v.back().second){
                v.back().second = max(a[i].r, v.back().second);
                a[i].group = 1;
            }
            else{
                flag = 1;
                a[i].group = 2;
            }
        }
        
        sort(a, a + n, comp);
        
//        for(int i = 0; i < n; i++){
//            cout<<a[i].first.first<<" "<<a[i].first.second<<endl;
//        }
        
        if(flag){
            for(int i = 0; i < n; i++){
                cout<<a[i].group<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"-1\n";
        }
    }
 
    return 0;
}
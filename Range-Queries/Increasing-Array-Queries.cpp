#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#if __has_include("../include/print_ostream.h")
    #include "../include/print_ostream.h"
#endif
using namespace std;
 
using ll = int64_t;
 
using vi = vector<int32_t>;
using vvi = vector<vi>;
using pi = pair<int32_t, int32_t>;
using vpi = vector<pi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using vb = vector<bool>;
using vc = vector<char>;
 
#define pb push_back
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define repr(i,a,b) for (int i = a; i >= b; --i)
 
constexpr uint32_t MOD = 1e9 + 7;
 
 
const int maxN = 2e5+1;
const int SIZE = 4*maxN;
 
int lo[SIZE], hi[SIZE];
ll a[maxN], ass[SIZE], mx[SIZE], sm[SIZE], ans[maxN];
vpi queries[maxN];
 
int len(int i){
    return hi[i]-lo[i]+1;
}
 
void assign(int i, ll val){
    ass[i] = mx[i] = val;
    sm[i] = val * len(i);
}
 
void push(int i){
    if(ass[i]){
        assign(2*i, ass[i]);
        assign(2*i+1, ass[i]);
        ass[i] = 0;
    }
}
 
void pull(int i){
    sm[i] = sm[2*i] + sm[2*i+1];
    mx[i] = max(mx[2*i], mx[2*i+1]);
}
 
void init(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if(l == r){
        sm[i] = a[l];
        return;
    }
    int m = (l+r)/2;
    init(2*i, l, m);
    init(2*i+1, m+1, r);
    pull(i);
}
 
void update(int i, int l, int r, ll val){
    if(l > hi[i] || r < lo[i])  return;
    if(l <= lo[i] && hi[i] <= r){
        assign(i, val);
        return;
    }
 
    push(i);
    update(2*i, l, r, val);
    update(2*i+1, l, r, val);
    pull(i);
}
 
int orderOf(int i, int l, int val){
    if(lo[i] == hi[i])                  return lo[i];
    push(i);
    int idx = -1;
    if(hi[2*i] <= l || mx[2*i] < val)   idx = orderOf(2*i+1, l, val);
    else                                idx = orderOf(2*i, l, val);
    pull(i);
    return idx;
}
 
ll sum(int i, int l, int r){
    if(l > hi[i] || r < lo[i])      return 0;
    if(l <= lo[i] && hi[i] <= r)    return sm[i];
 
    push(i);
    ll left = sum(2*i, l, r);
    ll right = sum(2*i+1, l, r);
    pull(i);
 
    return left+right;
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    int n, q; cin >> n >> q;
 
    rep(i, 1, n) 
        cin >> a[i];
 
    init(1, 1, n);
 
    rep(i, 0, q-1) {
        int a, b; cin >> a >> b;
        queries[a].emplace_back(b, i);   
    }
 
    rep(i, 2, n) 
        a[i] += a[i-1];
 
    repr(left, n, 1) {
        int val = a[left]-a[left-1];
        int modifyR = (mx[1] < val ? n+1 : orderOf(1, left, val));
        update(1, left, modifyR-1, val);
        for(pi q : queries[left]){
            int r = q.first;
            int id = q.second;
            ans[id] = sum(1, left, r) - (a[r]-a[left-1]);
        }
    }
 
    rep(i, 0, q-1) 
        cout << ans[i] << "\n";
 
    return 0;
}
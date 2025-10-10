#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
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



inline int removeOld(vi& elements, unordered_map<ll, int>& mp, int index) {
    return mp[elements[index]] == index;
}


inline int addNew(vi& elements, unordered_map<ll, int>& mp, int index, int k) {
    return !(mp.find(elements[index])!=mp.end() && mp[elements[index]]+k > index);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vi elements(n);
    rep(i, 0, n-1) cin >> elements[i];

    unordered_map<ll, int> mp;
    rep(i, 0, k-1) {
        mp[elements[i]] = i;
    }

    int cnt = mp.size();
    cout << cnt << " ";

    rep(i, k, n-1) {
        cnt -= removeOld(elements, mp, i-k);
        cnt += addNew(elements, mp, i, k);
        mp[elements[i]] = i;
        cout << cnt << " ";
    }


    
    return 0;
}
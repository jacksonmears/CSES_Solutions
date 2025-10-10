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


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);


    int n, k, x, a, b, c; cin >> n >> k >> x >> a >> b >> c;

    vl elements(n); elements[0] = x;
    rep(i, 1, n-1) {
        elements[i] = (a*elements[i-1] +b) % c;
    }

    vi prefix(n+1), suffix(n+1);

    rep(i, 0, n-1)
        prefix[i] = (i%k == 0) ? elements[i] : (prefix[i-1] | elements[i]);

    repr(i, n-1, 0)
        suffix[i] = (i%k == k-1) ? elements[i] : (suffix[i+1] | elements[i]);

    ll ans = 0;
    rep(i, 0, n-k) {
        int l = i, r = i + k - 1;
        int or_val = suffix[l] | prefix[r];
        ans ^= or_val;
    }

    std::cout << ans;

    
    return 0;
}
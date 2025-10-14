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
 
    constexpr int MAX_BIT = 20;
    constexpr int MAXX = 1 << 20;
 
    int n; cin >> n;
    vi elements(n), freq(MAXX);
    rep(i, 0, n-1) {
        cin >> elements[i];
        ++freq[elements[i]];
    }
 
    // (x | y) == x
    vi submask = freq;
    rep(i, 0, MAX_BIT-1)
        rep(mask, 0, MAXX-1)
            if (mask & (1 << i))
                submask[mask] += submask[mask ^ (1 << i)];
 
    // (x & y) == x
    vi supermask = freq;
    rep(i, 0, MAX_BIT-1)
        rep(mask, 0, MAXX-1)
            if (!(mask & (1 << i)))
                supermask[mask] += supermask[mask | (1 << i)];
 
    // (x & y) != 0
    // can use pointer OR std::move api here rather than copy entire freq because we don't need freq anymore. essentially changing ownership (could also just set submask to freq!!!! but it's not any faster and isn't as clear)
    vi* disjoint = &freq;
    rep(i, 0, MAX_BIT-1)
        rep(mask, 0, MAXX-1)
            if (mask & (1 << i))
                (*disjoint)[mask] = submask[((1<<MAX_BIT)-1) ^ mask];
    
    
    for (int x : elements) {
        int XOR = submask[x];                       // (x | y) == x
        int AND = supermask[x];                     // (x & y) == x
        int and_nonzero = n-(*disjoint)[x];            // (x & y) != 0
        cout << XOR << " " << AND << " " << and_nonzero << "\n";
    }
}
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


void solve() {

    int n; cin >> n;
    unordered_map<int, int> freq;
    set<int> mex;
    rep(i, 0, n) {
        mex.insert(i);
    }

    rep(i, 1, n) {
        int x; cin >> x;
        mex.erase(x);
        ++freq[x];
    }

    int mx = *mex.begin();

    unordered_map<int, vi> invFreq;
    for(auto& [f, s] : freq)
        invFreq[s].pb(f);

    set<int> vals;
    vals.insert(mx);

    rep(k, 0, n) {
        vals.erase(n-k+1);
        for (int i : invFreq[k]) {
            if (i <= min(mx, n-k)) 
                vals.insert(i);
        }

        cout << vals.size() << " ";
    }
    cout << "\n";



}



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);


    int t; cin >> t;
    while (t--) {
        solve();
    }



    
    return 0;
}
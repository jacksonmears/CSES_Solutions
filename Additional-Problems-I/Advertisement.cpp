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


    int n; cin >> n;
    stack<pl> st;
    ll mx = 0;
    rep(i, 0, n-1) {
        ll x; cin >> x;
        while (!st.empty() && x < st.top().first) {
            ll y = st.top().first; st.pop();
            mx = max(mx, st.empty() ? y*i : y*((i-1)-st.top().second));
        }
        st.emplace(x, i);
    }

    while (!st.empty()) {
        ll y = st.top().first; st.pop();
        mx = max(mx, st.empty() ? y*n : y*((n-1)-st.top().second));
    }

    cout << mx;

    
    return 0;
}
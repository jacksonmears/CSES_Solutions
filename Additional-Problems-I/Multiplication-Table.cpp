#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

using ll = uint64_t;

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

    ll n; cin >> n;

    ll target = (n * n + 1) / 2;
    ll low = 1, high = n * n, ans = 0;

    while (low <= high) {
        ll mid = (low + high) / 2;
        ll cnt = 0;

        rep(i, 1, n)
            cnt += min(n, mid / i);

        if (cnt >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }

    }

    cout << ans;

    return 0;
}
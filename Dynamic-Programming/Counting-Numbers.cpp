#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
constexpr int MOD = 1e9 + 7;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = a; i >= b; --i)
 
 
 
ll a, b, dp[20][11][2][2];
vi digits;

// prev_idx: 0..9 are digits, 10 means "no previous digit yet" (leading zeros so far)
ll dfs(int pos, int prev_idx, int tight, int lead) {
    if (pos == (int)digits.size()) {
        // we've constructed one number (including 0 when all digits were leading zeros)
        return 1;
    }
    ll &memo = dp[pos][prev_idx][tight][lead];
    if (memo != -1) return memo;

    memo = 0;
    int limit = tight ? digits[pos] : 9;
    for (int d = 0; d <= limit; ++d) {
        int next_lead = lead && (d == 0);
        // If not leading zeros and digit equals previous => invalid
        if (!next_lead && !lead && d == prev_idx) continue;
        // Compute next prev index:
        int next_prev = next_lead ? 10 : d;
        int next_tight = tight && (d == limit);
        memo += dfs(pos + 1, next_prev, next_tight, next_lead);
    }
    return memo;
}

ll count_up_to(ll x) {
    if (x < 0) return 0;
    if (x == 0) return 1; // only number 0

    digits.clear();
    while (x > 0) {
        digits.push_back((int)(x % 10));
        x /= 10;
    }
    reverse(digits.begin(), digits.end());
    // initialize dp with -1
    memset(dp, -1, sizeof(dp));
    // start at pos 0, prev = 10 (no prev), tight = 1, lead = 1 (we haven't placed non-zero yet)
    return dfs(0, 10, 1, 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b;

    cout << count_up_to(b) - count_up_to(a - 1);

    return 0;
}
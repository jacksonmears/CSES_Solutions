#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<bool> vb;
typedef vector<pl> vp;
typedef vector<vl> vvl;
constexpr ll MAX = 9e18;
constexpr ll MOD = 1e9 + 7;
constexpr int MAXN = 2e5+1;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (ll i = a; i <= b; i++)
#define repr(i, a, b) for (ll i = a; i >= b; i--)



ll N, M;
ll ways;

void dfs(const ll& row, const ll& mask, const ll& new_mask, map<ll,ll>& next) {
    if (row == N) {
        next[new_mask] = (next[new_mask] + ways) % MOD;
        return;
    }
    if (mask & (1<<row))
        dfs(row+1, mask, new_mask, next);
    else {
        if (row+1 < N && !(mask & (1<<(row+1))))
            dfs(row+2, mask, new_mask, next);
        dfs(row+1, mask, new_mask | (1<<row), next);
    }
}


map<ll, ll> computeHalf(const ll SIDE) {
    map<ll, ll> dp;
    dp[0] = 1;

    rep(_, 0, SIDE-1) {
        map<ll, ll> next;
        for (const auto &[mask, current_ways] : dp) {
            ways = current_ways;
            dfs(0, mask, 0, next);
        }

        dp.swap(next);
    }
    return dp;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> M;

    const ll LEFT = M/2;
    const ll RIGHT = M - LEFT;

    const map<ll,ll> left_ways = computeHalf(LEFT);
    map<ll,ll> right_ways = computeHalf(RIGHT);

    ll answer = 0;
    for (const auto &[mask, left] : left_ways) {
        if (right_ways.contains(mask)) {
            const ll right = right_ways[mask];
            answer = (answer + left * right) % MOD;
        }
    }

    cout << answer << "\n";
    return 0;
}

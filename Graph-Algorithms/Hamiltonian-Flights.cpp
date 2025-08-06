#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
constexpr ll MAX = 9e18;
constexpr ll MOD = 1e9 + 7;

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (ll i = a; i <= b; i++)



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n, m; cin >> n >> m;
    vector<vl> adj_matrix(n);
    rep(i, 0, m-1) {
        ll a, b; cin >> a >> b; a--; b--;
        adj_matrix[a].push_back(b);
    }

    const ll FULL_MASK = (1 << n) - 1;
    vector dp(1 << n, vl(n, 0));
    dp[1][0] = 1;

    rep(current_mask, 1, FULL_MASK) {
        rep(node, 0, n-1) {
            if (!(current_mask & (1 << node))) continue;
            if (dp[current_mask][node] == 0) continue;

            for (const ll child : adj_matrix[node]) {
                if (current_mask & (1 << child)) continue;
                const ll newMask = current_mask | (1 << child);
                dp[newMask][child] = (dp[newMask][child] + dp[current_mask][node]) % MOD;
            }
        }
    }

    cout << dp[FULL_MASK][n-1] << "\n";


    return 0;
}

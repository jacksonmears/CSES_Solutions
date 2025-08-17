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


struct State {
    ll rides;
    ll last_weight;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x; cin >> n >> x;
    vl weights(n);
    rep(i, 0, n-1) cin >> weights[i];

    const ll N = 1 << n;
    vector<State> dp(N, {n+1, 0});
    dp[0] = {1, 0};

    rep(mask, 0, N-1) {
        rep(i, 0, n-1) {
            if (!(mask & (1<<i))) {
                const ll NEW_MASK = mask | (1<<i);
                const State CURRENT = dp[mask];
                State option;

                if (CURRENT.last_weight + weights[i] <= x) {
                    option = {CURRENT.rides, CURRENT.last_weight + weights[i]};
                    if (option.rides < dp[NEW_MASK].rides ||
                        (option.rides == dp[NEW_MASK].rides && option.last_weight < dp[NEW_MASK].last_weight)) {
                        dp[NEW_MASK] = option;
                    }
                } else {
                    option = {CURRENT.rides + 1, weights[i]};
                    if (option.rides < dp[NEW_MASK].rides ||
                        (option.rides == dp[NEW_MASK].rides && option.last_weight < dp[NEW_MASK].last_weight)) {
                        dp[NEW_MASK] = option;
                    }
                }
            }
        }
    }

    cout << dp[N-1].rides << "\n";
}

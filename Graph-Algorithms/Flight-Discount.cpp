#include <bits/stdc++.h>
#include <regex>
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


typedef tuple<ll, ll, bool> node;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n, m; cin >> n >> m;
    vector<vector<pl>> adj_matrix(n+1);
    rep(i, 0, m-1) { ll a, b, c; cin >> a >> b >> c;
        adj_matrix[a].emplace_back(b, c);
    }

    vector<vector<ll>> dp(n+1, vl(2, LLONG_MAX));
    dp[1][0] = 0;

    priority_queue<node, vector<node>, greater<>> dijkstra; dijkstra.emplace(0,1, false);

    while (!dijkstra.empty()) {
        auto [current_cost, node, used_discount] = dijkstra.top(); dijkstra.pop();
        if (current_cost > dp[node][used_discount]) continue;
        for (auto &[child, weight] : adj_matrix[node]) {
            if (dp[child][used_discount] > current_cost + weight) {
                dp[child][used_discount] = current_cost + weight;
                dijkstra.emplace(dp[child][used_discount], child, used_discount);
            }

            if (!used_discount) {
                if (dp[child][1] > current_cost + weight / 2) {
                    dp[child][1] = current_cost + weight / 2;
                    dijkstra.emplace(dp[child][1], child, true);
                }
            }
        }
    }

    cout << dp[n][1];


    return 0;
}

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
    vector<vector<pl>> adj_matrix(n+1);
    rep(i, 0, m-1) {
        ll a, b, c; cin >> a >> b >> c;
        adj_matrix[a].pb(mp(b, c));
    }

    vl bellman_ford(n+1, 0);
    vl parent(n+1, -1);
    ll cycle_found = -1;

    rep(i, 0, n-1) {
        cycle_found = -1;
        rep(node, 1, n) {
            for (auto &[child, weight] : adj_matrix[node]) {
                if (bellman_ford[node] + weight < bellman_ford[child]) {
                    bellman_ford[child] = bellman_ford[node] + weight;
                    parent[child] = node;
                    cycle_found = child;
                }
            }
        }
    }

    if (cycle_found == -1) return cout << "NO\n", 0;

    rep(i, 0, n-1) cycle_found = parent[cycle_found];

    vl cycle;
    ll cur = cycle_found;
    do {
        cycle.pb(cur);
        cur = parent[cur];
    } while (cur != cycle_found);
    cycle.pb(cycle_found);
    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for (auto i : cycle) cout << i << " ";

    return 0;
}

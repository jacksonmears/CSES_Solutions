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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k; cin >> n >> m >> k;
    vector<vector<pl>> adj(n + 1);
    rep(i, 0, m-1) {
        ll a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }

    priority_queue<pl, vector<pl>, greater<>> dijkstra; dijkstra.emplace(0, 1);
    vector<vl> dist(n + 1);

    while (!dijkstra.empty()) {
        auto [cost, node] = dijkstra.top(); dijkstra.pop();

        if (dist[node].size() >= k) continue;
        dist[node].push_back(cost);

        for (auto &[child, price] : adj[node]) {
            ll new_cost = cost + price;
            if (dist[child].size() < k) {
                dijkstra.emplace(new_cost, child);
            }
        }
    }

    for (const ll i : dist[n])
        cout << i << " ";

    cout << "\n";

    return 0;
}

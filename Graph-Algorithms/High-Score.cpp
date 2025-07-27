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


ll n, m;
vector<vector<pl>> adj, rev_adj;
vector<bool> visited_from_start, visited_to_end;

void dfs(ll node, vector<vector<pl>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (auto &[next, _] : graph[node]) {
        if (!visited[next]) dfs(next, graph, visited);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    adj = vector<vector<pl>>(n+1);
    rev_adj = vector<vector<pl>>(n+1);

    rep(i, 0, m-1) {
        ll a, b, x; cin >> a >> b >> x;
        adj[a].pb(mp(b, x));
        rev_adj[b].pb(mp(a, x));
    }

    vector<ll> bellmen_ford(n+1, INT_MIN);
    bellmen_ford[1] = 0;

    rep(bellmen_ford_iterations, 1, n-1) {
        rep(node, 1, n) {
            for (auto &[child, weight] : adj[node]) {
                if (bellmen_ford[node] != INT_MIN && bellmen_ford[node] + weight > bellmen_ford[child]) {
                    bellmen_ford[child] = bellmen_ford[node] + weight;
                }
            }
        }
    }

    vector<bool> affected(n+1, false);
    rep(node, 1, n) {
        for (auto &[child, weight] : adj[node]) {
            if (bellmen_ford[node] != INT_MIN && bellmen_ford[node] + weight > bellmen_ford[child]) affected[child] = true;
        }
    }

    visited_from_start = vector<bool>(n+1, false);
    visited_to_end = vector<bool>(n+1, false);

    dfs(1, adj, visited_from_start);
    dfs(n, rev_adj, visited_to_end);

    rep(i, 1, n) {
        if (affected[i] && visited_from_start[i] && visited_to_end[i]) {
            return cout << "-1", 0;
        }
    }
    bellmen_ford[n] != INT_MIN ? cout << bellmen_ford[n] : cout << "-1";


    return 0;
}

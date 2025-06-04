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
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)





int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll n, m; cin >> n >> m;

    vector<vl> connections(n + 1);
    vl parent(n + 1);
    vector<bool> visited(n + 1);


    REP(i, 0, m - 1) {
        ll a, b; cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    queue<ll> q; q.push(1);
    visited[1] = true; parent[1] = -1;

    while (!q.empty()) {
        ll node = q.front(); q.pop();
        for (ll neighbor : connections[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    if (!visited[n]) return cout << "IMPOSSIBLE", 0;


    vector<ll> path;
    for (ll v = n; v != -1; v = parent[v]) path.push_back(v);

    cout << path.size() << '\n';
    REP(i, 0, path.size()-1) cout << path[path.size()-1-i] << " ";



    return 0;
}
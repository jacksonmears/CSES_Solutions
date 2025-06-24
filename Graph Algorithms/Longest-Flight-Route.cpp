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
#define REP(i,a,b) for (ll i = a; i <= b; i++)



constexpr ll INF = -1e18;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n, m; cin >> n >> m;
    // inDegrees tracks how many nodes are directed to a specific node (1->5 and 4->5 would return 2 inDegrees for element 5)
    vector<vl> graph(n + 1); vector<ll> inDegrees(n + 1, 0);

    REP(i, 0, m-1) {
        ll a, b; cin >> a >> b;
        graph[a].pb(b);
        inDegrees[b]++;
    }

    queue<ll> bfs;
    REP(i, 1, n) if (inDegrees[i] == 0) bfs.push(i);

    // typical graph theory has u var as currentNode and v as neighborNode so keep that in mind for this and future graphing solutions.
    // Kahn's algo for topological sort
    vector<ll> topography;
    while (!bfs.empty()) {
        ll u = bfs.front(); bfs.pop();
        topography.pb(u);
        for (ll v : graph[u]) {
            inDegrees[v]--;
            if (inDegrees[v] == 0) bfs.push(v);
        }
    }

    vector<ll> dp(n + 1, INF);
    vector<ll> parent(n + 1, -1);
    dp[1] = 0;

    for (ll u : topography) {
        for (ll v : graph[u]) {
            if (dp[u] + 1 > dp[v]) {
                dp[v] = dp[u] + 1;
                parent[v] = u;
            }
        }
    }


    vector<ll> path;
    for (ll currentNode = n; currentNode != -1; currentNode = parent[currentNode]) path.pb(currentNode);
    ranges::reverse(path.begin(), path.end());

    if (dp[n] == INF || path[0] != 1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    cout << path.size() << '\n';
    for (ll city : path) cout << city << ' ';

    return 0;
}

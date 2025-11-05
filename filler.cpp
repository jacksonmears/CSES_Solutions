#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

using vi = vector<int32_t>;
using vvi = vector<vi>;
using pi = pair<int32_t, int32_t>;
using vpi = vector<pi>;
using vl = vector<ll>;

#define pb push_back
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define repr(i,a,b) for (int i = a; i >= b; --i)

const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;

int n, m;

vl fillDist(int start, vector<vpi>& edges) {
    vl dist(n+1, LLONG_MAX);
    dist[start] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> dijkstra;
    dijkstra.emplace(0ll, start);

    while (!dijkstra.empty()) {
        auto [current_weight, node] = dijkstra.top(); dijkstra.pop();
        if (current_weight > dist[node]) continue;

        for (auto [child, edge_weight] : edges[node]) {
            if (dist[child] > edge_weight + current_weight) {
                dist[child] = edge_weight + current_weight;
                dijkstra.emplace(dist[child], child);
            }
        }
    }

    return dist;
}

vvi buildDAG(vector<vpi>& edges, vl& dist1, vl& dist2, ll mn_path) {
    vvi dag(n+1);
    rep(u, 1, n) {
        for (auto [v, w] : edges[u]) {
            if (dist1[u] + w + dist2[v] == mn_path)
                dag[u].pb(v); // include duplicates
        }
    }
    return dag;
}

// count1: paths from start, count2: paths to end along same DAG
pair<vi,vi> fillCountPaths(vvi& dag, vl& dist, int start, int end) {
    vi count1(n+1), count2(n+1);
    count1[start] = 1;
    count2[end] = 1;

    // Topo order for forward paths (start -> node)
    vi topo_inc(n);
    iota(topo_inc.begin(), topo_inc.end(), 1);
    sort(topo_inc.begin(), topo_inc.end(), [&](int a,int b){ return dist[a] < dist[b]; });

    for(int u : topo_inc) {
        for(int v : dag[u]) {
            count1[v] = (count1[v] + count1[u]) % MOD1;
        }
    }

    // Topo order for backward paths (node -> end)
    vi topo_dec = topo_inc;
    reverse(topo_dec.begin(), topo_dec.end());
    for(int u : topo_dec) {
        for(int v : dag[u]) {
            count2[u] = (count2[u] + count2[v]) % MOD1;
        }
    }

    return {count1, count2};
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    vector<vpi> edges(n+1);

    int a,b,c;
    rep(i,1,m) {
        cin >> a >> b >> c;
        edges[a].emplace_back(b,c);
    }

    vl dist1 = fillDist(1, edges);
    vl dist2 = fillDist(n, edges); // keep using original edges for DAG

    vvi dag = buildDAG(edges, dist1, dist2, dist1[n]);
    auto [count1, count2] = fillCountPaths(dag, dist1, 1, n);

    ll total = count1[n];

    vi ans;
    rep(u,1,n) {
        if (dist1[u] + dist2[u] == dist1[n] &&
            1LL * count1[u] * count2[u] % MOD1 == total)
            ans.pb(u);
    }

    cout << ans.size() << "\n";
    for(int u : ans) cout << u << " ";
}

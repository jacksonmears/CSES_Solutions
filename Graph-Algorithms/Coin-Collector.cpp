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


const ll MAXN = 1e5 + 5;
vl adj_matrix[MAXN], reverse_adj[MAXN], order;
bool seen[MAXN];
ll coins[MAXN], sccCoins[MAXN];
ll sccID[MAXN];
vl dag[MAXN];
ll dp[MAXN];

void dfs1(const ll node) {
    seen[node] = true;
    for (const ll child : adj_matrix[node])
        if (!seen[child]) dfs1(child);
    order.pb(node);
}

void dfs2(const ll node, const ll componentID) {
    sccID[node] = componentID;
    sccCoins[componentID] += coins[node];
    seen[node] = true;
    for (const ll child : reverse_adj[node])
        if (!seen[child]) dfs2(child, componentID);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n, m; cin >> n >> m;
    rep(i, 1, n) cin >> coins[i];

    rep(i, 0, m-1) {
        ll a, b; cin >> a >> b;
        adj_matrix[a].pb(b);
        reverse_adj[b].pb(a);
    }

    // Kosaraju's Algorithm
    // order vertices by time (technically the last node to be visited will be first in order with DFS,
    // but we traverse the order array in reverse so truly the first nodes to be seen are first)
    rep(i, 1, n) if (!seen[i]) dfs1(i);


    // create the scc via reverse adj matrix
    // because we reverse the graph the first cycle will be initiated by the first node and will be "trapped" in their own cycle
    // imagine you have cycle A connect to cycle B via a one way connection from A to B. That cycle A and the fact it's connected to the rest of the graph
    // including cycle B make it impossible to apply many algorithms. However, when we reverse the edge directions, it makes sense that cycles remain cycles
    // but when we begin at cycle A, it no longer reaches cycle B because the edge was reversed so it has been isolated! That is the first step of Kosaraju's algo!

    // revert seen back to original state of all elements false. Creating a secondary array would be 2n memory (more space) and same time.
    fill(seen, seen + n + 1, false);
    ll componentID = 0;
    for (ll i = n - 1; i >= 0; i--) {
        if (const ll node = order[i]; !seen[node]) {
            dfs2(node, componentID);
            componentID++;
        }
    }

    // creating edges between scc
    rep(node, 1, n) {
        for (const ll child : adj_matrix[node]) {
            if (sccID[node] != sccID[child])
                dag[sccID[node]].push_back(sccID[child]);
        }
    }


    // finding inDegrees for each scc, preparing to use Kahn's topological sorting algo so we can use DP to find answer
    // use SuperNodes to represent each SCC. they aren't real nodes merely titles for a maximal set of nodes mutually reachable.
    vector inDegrees(componentID, 0);
    rep(superNode, 0, componentID-1) {
        // sorting dag edges to other scc make it easier to remove duplicate edges (2 edges from A to B from different nodes, but we only need to count 1 edge between scc)
        ranges::sort(dag[superNode]);
        dag[superNode].erase(ranges::unique(dag[superNode]).begin(), dag[superNode].end());
        for (const ll child : dag[superNode]) inDegrees[child]++;
    }

    // initialize kahn's algo
    // tracks that the cycle A, the first cycle found would be first in topological sort
    // without kahn's we couldn't effectively find DP because we'd traverse over the same node several times
    // now, after we go through cycle A (no inDegrees) we know that those DP values are final!
    queue<ll> q;
    rep(superNode, 0, componentID-1) {
        if (inDegrees[superNode] == 0) q.push(superNode);
        dp[superNode] = sccCoins[superNode];
    }

    // standard graphical dp solution while continuing kahn's algo by reducing child SCC inDegrees after parent SCC visits!
    ll ans = 0;
    while (!q.empty()) {
        const ll superNode = q.front(); q.pop();
        ans = max(ans, dp[superNode]);
        for (const ll childSCC : dag[superNode]) {
            dp[childSCC] = max(dp[childSCC], dp[superNode] + sccCoins[childSCC]);
            inDegrees[childSCC]--;
            if (inDegrees[childSCC] == 0) q.push(childSCC);
        }
    }

    cout << ans << "\n";
    return 0;
}


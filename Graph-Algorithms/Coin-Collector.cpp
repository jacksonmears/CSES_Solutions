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

    // order vertices by  time
    rep(i, 1, n) if (!seen[i]) dfs1(i);

    // Kosaraju's Algorithm
    fill(seen, seen + n + 1, false);
    ll componentID = 0;
    for (ll i = n - 1; i >= 0; i--) {
        const ll node = order[i];
        if (!seen[node]) {
            dfs2(node, componentID);
            componentID++;
        }
    }

    rep(node, 1, n) {
        for (const ll child : adj_matrix[node]) {
            if (sccID[node] != sccID[child])
                dag[sccID[node]].push_back(sccID[child]);
        }
    }

    vector inDegrees(componentID, 0);
    rep(node, 0, componentID-1) {
        ranges::sort(dag[node]);
        dag[node].erase(ranges::unique(dag[node]).begin(), dag[node].end());
        for (const ll child : dag[node]) inDegrees[child]++;
    }

    queue<ll> q;
    rep(i, 0, componentID-1) {
        if (inDegrees[i] == 0) q.push(i);
        dp[i] = sccCoins[i];
    }

    ll ans = 0;
    while (!q.empty()) {
        const ll node = q.front(); q.pop();
        ans = max(ans, dp[node]);
        for (const ll child : dag[node]) {
            dp[child] = max(dp[child], dp[node] + sccCoins[child]);
            inDegrees[child]--;
            if (inDegrees[child] == 0) q.push(child);
        }
    }

    cout << ans << "\n";
    return 0;
}


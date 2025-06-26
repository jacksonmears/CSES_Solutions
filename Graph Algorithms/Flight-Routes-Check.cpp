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




vector<bool> visited;
ll n;

void dfs(ll currentNode, vector<vl>& graph) {
    visited[currentNode] = true;
    for (int adjacentNodes : graph[currentNode]) {
        if (!visited[adjacentNodes]) dfs(adjacentNodes, graph);
    }
}


bool visitedAllCheck(const bool forward) {
    REP(i, 1, n) {
        if (!visited[i]) {
            (!forward) ? cout << "NO\n" << i << " " << 1 : cout << "NO\n" << 1 << " " << i;
            return false;
        }
    }
    return true;
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll m; cin >> n >> m;
    visited = vector<bool>(n+1, false);

    vector<vl> adjacencyGraph(n+1);
    vector<vl> reverseAdjacencyGraph(n+1);
    REP(i, 0, m-1) {
        ll a, b; cin >> a >> b;
        adjacencyGraph[a].pb(b);
        reverseAdjacencyGraph[b].pb(a);
    }

    dfs(1, adjacencyGraph);
    if (!visitedAllCheck(true)) return 0;

    visited = vector<bool>(n+1, false);
    dfs(1, reverseAdjacencyGraph);
    if (!visitedAllCheck(false)) return 0;

    cout << "YES";

    return 0;
}
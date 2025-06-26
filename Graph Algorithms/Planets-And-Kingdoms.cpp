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
vl component;
stack<ll> kosarajuStack; // strongly connected components



void dfs1(const ll currentNode, vector<vl>& graph) {
    visited[currentNode] = true;
    for (int adjacentNodes : graph[currentNode]) {
        if (!visited[adjacentNodes]) dfs1(adjacentNodes, graph);
    }
    kosarajuStack.push(currentNode);
}

void dfs2(const ll currentNode, vector<vl>& graph, const ll componentLabel) {
    component[currentNode] = componentLabel;
    visited[currentNode] = true;
    for (int adjacencyNode : graph[currentNode]) {
        if (!visited[adjacencyNode]) dfs2(adjacencyNode, graph, componentLabel);
    }
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

    REP(i, 1, n) if (!visited[i]) dfs1(i, adjacencyGraph);

    visited = vector<bool>(n+1, false);
    component = vl(n+1, 0);
    ll componentLabel = 1;
    while (!kosarajuStack.empty()) {
        ll node = kosarajuStack.top(); kosarajuStack.pop();
        if (!visited[node]) {
            dfs2(node, reverseAdjacencyGraph, componentLabel);
            componentLabel++;
        }
    }

    cout << componentLabel-1 << "\n";
    REP(i, 1, n) cout << component[i] << " ";

    return 0;
}

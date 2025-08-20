#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
constexpr int MOD = 1e9 + 7;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define repr(i, a, b) for (int i = a; i >= b; i--)

struct Edge {
    int node, child, weight;
};

bool comparison(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// disjoint set union (union-find) to keep track of connected components
struct DSU {
    vector<int> parent, rank;

    DSU(int node) : parent(node+1), rank(node+1,0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(const int node) {
        if (parent[node] != node)
            parent[node] = find(parent[node]);
        return parent[node];
    }
    bool unite(int node, int child) {
        node = find(node); child = find(child);
        if (node == child)
            return false;
        if (rank[node] < rank[child])
            swap(node, child);
        parent[child] = node;
        if (rank[node] == rank[child])
            rank[node]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<Edge> edges(m);
    rep(i, 0, m-1)
        cin >> edges[i].node >> edges[i].child >> edges[i].weight;

    ranges::sort(edges, comparison);

    DSU dsu(n);
    long long min_weight = 0;
    int edges_used = 0;

    for(auto &e : edges) {
        auto [node,child,weight] = e;
        if(dsu.unite(node, child)) {
            min_weight += weight;
            edges_used++;
        }
    }

    (edges_used != n-1) ?  cout << "IMPOSSIBLE" : cout << min_weight;

    return 0;
}

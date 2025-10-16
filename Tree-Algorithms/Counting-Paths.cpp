#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

using vi = vector<int32_t>;
using vvi = vector<vi>;
using pi = pair<int32_t, int32_t>;
using vpi = vector<pi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using vb = vector<bool>;
using vc = vector<char>;

#define pb push_back
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define repr(i,a,b) for (int i = a; i >= b; --i)

constexpr uint32_t MOD = 1e9 + 7;
constexpr uint32_t MAXN = 2e5+1;
constexpr int32_t LOGN = 20;


int n, m;
vi edges[MAXN];
int binary_lifting[MAXN][20];        
int depth[MAXN], parent[MAXN], cnt[MAXN];

void build_binary_lifting() {
    deque<int> bfs;
    bfs.pb(1);
    parent[1] = 0, depth[1] = 0;

    while (!bfs.empty()) {
        int node = bfs.front(); bfs.pop_front();
        for (int child : edges[node]) {
            if (child == parent[node]) continue;
            parent[child] = node;
            depth[child] = depth[node]+1;
            bfs.pb(child);
        }
    }

    // up[u][0] = parent (or itself for root)
    rep(node, 1, n) {
        binary_lifting[node][0] = (!parent[node] ? node : parent[node]);
    }

    rep(bit, 1, LOGN-1) {
        rep(node, 1, n) {
            binary_lifting[node][bit] = binary_lifting[binary_lifting[node][bit-1]][bit-1];
        }
    }
}

int getLCA(int a, int b) {

    if (depth[a] < depth[b]) swap(a,b);
    int diff = depth[a] - depth[b];

    for (int bit = 0; diff; ++bit) {
        if (diff & 1) a = binary_lifting[a][bit];
        diff >>= 1;
    }

    if (a == b) return a;

    repr(bit, LOGN-1, 0) {
        if (binary_lifting[a][bit] != binary_lifting[b][bit]) {
            a = binary_lifting[a][bit];
            b = binary_lifting[b][bit];
        }
    }

    return binary_lifting[a][0];
}

int dfs(int node, int parent) {
    int sum = cnt[node];
    for (int child : edges[node]) {
        if (child == parent) continue;
        sum += dfs(child, node);
    }
    cnt[node] = sum;
    return sum;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    int a, b;
    rep(i, 0, n-2) {
        cin >> a >> b;
        edges[a].pb(b);
        edges[b].pb(a);
    }

    build_binary_lifting();

    int u, v, lca;
    rep(i, 0, m-1) {
        cin >> u >> v;
        lca = getLCA(u,v);
        cnt[u] += 1;
        cnt[v] += 1;
        cnt[lca] -= 1;
        if (parent[lca] != 0) cnt[parent[lca]] -= 1;
    }

    dfs(1, 0);

    rep(i, 1, n) cout << cnt[i] << ' ';


    return 0;
}

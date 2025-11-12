#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#if __has_include("../include/print_ostream.h")
    #include "../include/print_ostream.h"
#endif
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

constexpr int MAXN = 2e5+1;


void dfs(int node, int parent, int& timer, vi& disc, vi& low, vvi& edges, vpi& bridges) {

    disc[node] = low[node] = ++timer;

    for (int child : edges[node]) if (child != parent) {

        if (!disc[child]) {
            dfs(child, node, timer, disc, low, edges, bridges);
            low[node] = min(low[node], low[child]);
            if (low[child] > disc[node]) 
                bridges.emplace_back(node, child);

        } 
        else low[node] = min(low[node], disc[child]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;

    int timer = 0;
    vi disc(n+1), low(n+1);
    vvi edges(n+1);
    vpi bridges;

    rep(i, 1, m) {
        int a, b; cin >> a >> b;
        edges[a].pb(b);
        edges[b].pb(a);
    }

    rep(i, 1, n) 
        if (!disc[i]) 
            dfs(i, -1, timer, disc, low, edges, bridges);

    cout << bridges.size() << "\n";
    for (auto [node, child] : bridges)
        cout << node << " " << child << "\n";

    
    return 0;
}
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
 
const int MAXN = 501;
vi edges[MAXN];
int capacity[MAXN][MAXN]; 
int parent[MAXN];
bitset<MAXN> reachable;
bitset<MAXN> seen;
 
int maxFlowBFS(int sink) { 
    ranges::fill(parent, -1);
    parent[1] = -2;
 
    queue<pi> bfs; bfs.emplace(1, INT_MAX); 
    while(!bfs.empty()) {
        auto [node, flow] = bfs.front(); bfs.pop();
 
        for(int child : edges[node]) {
            if(parent[child] == -1 && capacity[node][child]) {
                parent[child] = node;
                int new_flow = min(flow, capacity[node][child]);
                if(child == sink) return new_flow;
                bfs.push({child, new_flow});
            }
        }
    }
    return 0;
}
 
 
void updateCapacities(int& flow, int new_flow, int sink) {
    flow += new_flow;
    int node = sink;
    while(node != 1) {
        int prev = parent[node];
        capacity[prev][node] -= new_flow;
        capacity[node][prev] += new_flow;
        node = prev;
    }
}
 
 
void maxflow(int sink) { 
    int flow = 0, new_flow;
 
    while((new_flow = maxFlowBFS(sink))) 
        updateCapacities(flow, new_flow, sink);

}
 
 
void fillReachable() {
    queue<int> reachableBFS; reachableBFS.push(1);
    reachable.set(1);
 
    while (!reachableBFS.empty()) {
        int node = reachableBFS.front(); reachableBFS.pop();
 
        for (int child : edges[node]) {
            if (!reachable[child] && capacity[node][child]) {
                reachable.set(child);
                reachableBFS.push(child);
            }
        }
    }
}
 
vpi getAns(bitset<MAXN>& reachable) {
    vpi ans;
    queue<int> bfs; bfs.push(1);
 
    while (!bfs.empty()) {
        int node = bfs.front(); bfs.pop();
        if (seen[node]) continue;
 
        seen.set(node);

        
        for (int child : edges[node]) {
            if (!reachable[child])
                ans.emplace_back(node, child);
            else 
                bfs.push(child);
        }
    }
 
    return ans;
}
 
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    int n, m; cin >> n >> m;
    rep(i, 0, m-1) {
        int a, b; cin >> a >> b;
        edges[a].pb(b);
        edges[b].pb(a); 
        capacity[a][b] = 1; 
        capacity[b][a] = 1; 
    }
 
    maxflow(n);
 
    fillReachable();
 
    vpi ans = getAns(reachable);
 
    cout << ans.size() << "\n";
    for (auto p : ans) cout << p.first << " " << p.second << "\n";
 
    return 0;
}
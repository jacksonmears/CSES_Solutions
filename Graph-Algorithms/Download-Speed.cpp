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
ll capacity[MAXN][MAXN]; 
int parent[MAXN];
 
ll bfs(int start, int sink) { 
    ranges::fill(parent, -1);
    parent[start] = -2;
 
    queue<pair<int,ll>> bfs; bfs.push({start, LLONG_MAX}); 
    while(!bfs.empty()) {
        int node = bfs.front().first;
        ll flow = bfs.front().second;
        bfs.pop();
 
        for(int child : edges[node]) {
            if(parent[child] == -1 && capacity[node][child] > 0) {
                parent[child] = node;
                ll new_flow = min(flow, capacity[node][child]);
                if(child == sink) return new_flow;
                bfs.push({child, new_flow});
            }
        }
    }
    return 0;
}
 
 
void updateCapacities(ll& flow, ll new_flow, int start, int sink) {
    flow += new_flow;
    int node = sink;
    while(node != start) {
        int prev = parent[node];
        capacity[prev][node] -= new_flow;
        capacity[node][prev] += new_flow;
        node = prev;
    }
}
 
 
ll maxflow(int start, int sink) { 
    ll flow = 0, new_flow;
 
    while((new_flow = bfs(start, sink))) 
        updateCapacities(flow, new_flow, start, sink);
    
    return flow;
}
 
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    int n, m; cin >> n >> m;
    rep(i, 0, m-1) {
        int a, b, c; cin >> a >> b >> c;
        edges[a].pb(b);
        edges[b].pb(a); 
        capacity[a][b] += c; 
    }
 
    cout << maxflow(1, n) << endl;
}
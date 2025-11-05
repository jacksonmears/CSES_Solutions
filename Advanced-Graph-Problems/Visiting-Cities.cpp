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
 
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distrib((ll) 1e9, (ll) 2e9);
const ll MOD1 = distrib(rng);
const ll MOD2 = distrib(rng);
 

constexpr int maxN = 1e5+1;
int n, m;


using edge = pair<int,ll>;
using node = pair<ll,int>;

struct Path_Count {
    vl count1;
    vl count2;
};
 
 
void dijkstra(vector<vector<edge>>& edges, vl& dist, Path_Count& path, int source){

    dist[source] = 0;

    path.count1[source] = 1;
    path.count2[source] = 1;

    priority_queue<node, vector<node>, greater<node>> min_heap;
    min_heap.push({0, source});

    while(!min_heap.empty()){
        auto [cur_dist, node] = min_heap.top(); min_heap.pop();
 
        if(cur_dist > dist[node])   continue;
        for (auto [child, edge_weight] : edges[node]) {
            if(dist[child] > cur_dist+edge_weight){
                path.count1[child] = path.count1[node];
                path.count2[child] = path.count2[node];

                dist[child] = cur_dist+edge_weight;
                min_heap.emplace(cur_dist+edge_weight, child);
            } else if(dist[child] == cur_dist+edge_weight){

                path.count1[child] = (path.count1[child] + path.count1[node]) % MOD1;
                path.count2[child] = (path.count2[child] + path.count2[node]) % MOD2;
            }
        }
    }
}

void init_paths(Path_Count& path1, Path_Count& path2) {
    path1.count1.assign(n+1, 0);
    path1.count2.assign(n+1, 0);

    path2.count1.assign(n+1, 0);
    path2.count2.assign(n+1, 0);
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    cin >> n >> m;
 
    vector<vector<edge>> edges(n+1);
    vector<vector<edge>> redges(n+1);

    vl dist1(n+1, LLONG_MAX), dist2(n+1, LLONG_MAX);

    Path_Count path1; 
    Path_Count path2;
    init_paths(path1, path2);
 
    int a, b, c;
    rep(i, 1, m) {
        cin >> a >> b >> c;
        edges[a].emplace_back(b, c);
        redges[b].emplace_back(a, c);
    }
 
    dijkstra(edges, dist1, path1, 1);
    dijkstra(redges, dist2, path2, n);
 
    ll tot1 = path1.count1[n], tot2 = path1.count2[n];

    vi ans;
    rep(u, 1, n) {
        ll ways1 = (path1.count1[u] * path2.count1[u]) % MOD1;
        ll ways2 = (path1.count2[u] * path2.count2[u]) % MOD2;
        if(ways1 == tot1 && ways2 == tot2 && dist1[u] + dist2[u] == dist1[n])
            ans.pb(u);
    }
 
    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " ";
 
}
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
 
 
typedef pair<int,ll> edge;
typedef pair<ll,int> node;
const int maxN = 1e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distrib((ll) 1e9, (ll) 2e9);
const ll MOD1 = distrib(rng);
const ll MOD2 = distrib(rng);
 
int N, M;
ll paths[2][2][maxN];
 
 
void dijkstra(vector<vector<edge>>& edges, vl& dist, int type, int source){
    priority_queue<node, vector<node>, greater<node>> Q;
    dist[source] = 0;
    paths[type][0][source] = 1;
    paths[type][1][source] = 1;
    Q.push({0, source});
    while(!Q.empty()){
        int u = Q.top().second;
        ll d = Q.top().first;
        Q.pop();
 
        if(d > dist[u])   continue;
        for (auto [child, edge_weight] : edges[u]) {
            if(dist[child] > d+edge_weight){
                paths[type][0][child] = paths[type][0][u];
                paths[type][1][child] = paths[type][1][u];
                dist[child] = d+edge_weight;
                Q.emplace(d+edge_weight, child);
            } else if(dist[child] == d+edge_weight){
                paths[type][0][child] += paths[type][0][u];
                paths[type][0][child] %= MOD1;
                paths[type][1][child] += paths[type][1][u];
                paths[type][1][child] %= MOD2;
            }
        }
    }
}
 
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    cin >> N >> M;
 
    vector<vector<edge>> edges(N+1);
    vector<vector<edge>> redges(N+1);

    vl dist1(N+1, LLONG_MAX), dist2(N+1, LLONG_MAX);
    vl paths1(N+1), paths2(N+1);
 
    int a, b, c;
    rep(i, 1, M) {
        cin >> a >> b >> c;
        edges[a].emplace_back(b, c);
        redges[b].emplace_back(a, c);
    }
 
    dijkstra(edges, dist1, 0, 1);
    dijkstra(redges, dist2, 1, N);
 
    ll tot1 = paths[0][0][N], tot2 = paths[0][1][N];

    vi ans;
    rep(u, 1, N) {
        ll ways1 = (paths[0][0][u] * paths[1][0][u]) % MOD1;
        ll ways2 = (paths[0][1][u] * paths[1][1][u]) % MOD2;
        if(ways1 == tot1 && ways2 == tot2 && dist1[u] + dist2[u] == dist1[N])
            ans.pb(u);
    }
 
    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " ";
 
}
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


const int MAXN = 505;
int n, m;
vi edges[MAXN];
ll capacity[MAXN][MAXN]; 
ll parent[MAXN];

// sink == end
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

ll maxflow(int start, int sink) { 
    ll flow = 0, new_flow;

    while((new_flow = bfs(start, sink))) {
        flow += new_flow;
        int node = sink;
        while(node != start) {
            int prev = parent[node];
            capacity[prev][node] -= new_flow;
            capacity[node][prev] += new_flow;
            node = prev;
        }
    }
    return flow;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    rep(i, 0, m-1) {
        int a, b, c; cin >> a >> b >> c;
        edges[a].pb(b);
        edges[b].pb(a); 
        capacity[a][b] += c; 
    }

    cout << maxflow(1, n) << endl;
}

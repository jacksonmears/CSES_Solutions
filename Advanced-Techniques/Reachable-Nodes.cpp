#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
typedef vector<char> vc;
constexpr int MOD = 1e9 + 7;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = a; i >= b; --i)


 
constexpr int MAXN = 5e4+1;
bitset<MAXN> reachableNodes[MAXN];


// at the time of submission probably my favorite solution to date. from bitset substituting sets to using pragma targets to utilize opimizing registers
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vvi edges(n+1), reverseEdges(n+1);
    vi outdeg(n+1);
    rep(i, 0, m-1) {
        int a, b; cin >> a >> b;
        edges[a].pb(b);
        reverseEdges[b].pb(a);
        ++outdeg[a];
    }

    queue<int> q;
    rep(i, 1, n)
        if (!outdeg[i]) q.push(i);

    vi topo;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        topo.pb(node);
        for (int parent : reverseEdges[node])
            if (--outdeg[parent] == 0) q.push(parent);
    }

    for (int node : topo) {
        reachableNodes[node].set(node);
        for (int child : edges[node])
            reachableNodes[node] |= reachableNodes[child];
    }

    rep(i, 1, n) cout << reachableNodes[i].count() << " ";

    return 0;
}
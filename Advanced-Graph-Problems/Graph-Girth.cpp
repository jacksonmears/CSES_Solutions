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
constexpr uint32_t MAXN = 2501;

int n, m;

int bfs(int i, vvi& edges) 
{
    int l_mn = INT_MAX;
    vi depth(n+1);
    bitset<MAXN> seen;

    queue<pi> bfs; bfs.emplace(i, -1);

    while(!bfs.empty()) 
    {
        auto [node, parent] = bfs.front(); bfs.pop();
        
        for (int child : edges[node]) if (child != parent) 
        {
            if (seen[child]) 
            {
                l_mn = min(l_mn, depth[node]+depth[child]+1);
                continue;
            }

            depth[child] = depth[node]+1;
            seen.set(child);
            bfs.emplace(child, node);
        }
    }

    return l_mn;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);


    cin >> n >> m;
    
    vvi edges(n+1);

    rep(i, 1, m) 
    {
        int a, b; cin >> a >> b;
        edges[a].pb(b);
        edges[b].pb(a);
    }

    int mn = INT_MAX;
    rep(i, 1, n) 
        mn = min(mn, bfs(i, edges));
    
    
    cout << (mn == INT_MAX ? -1 : mn);

    return 0;
}
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

constexpr int MAXN = 16+1;


class DFS {
public:

    DFS(){}
    DFS(int n_, int m_) : n(n_), m(m_) {
        rep(i, 1, m) {
            int a,b; cin >> a >> b;
            edges[a].pb(b);
            edges[b].pb(a);
        }
    }


    bool valid(int node, int c) {
        for (int nb : edges[node])
            if (color[nb] == c) return false;
        return true;
    }

    void dfs(int node, int used) {
        if (used >= best) return;
        if (node > n) {
            best = used;
            bestColor.assign(color, color+n+1);
            return;
        }
        for (int c = 1; c <= used; ++c) {
            if (valid(node, c)) {
                color[node] = c;
                dfs(node + 1, used);
                color[node] = 0;
            }
        }

        color[node] = used + 1;
        dfs(node + 1, used + 1);
        color[node] = 0;
    }

    inline void printBestResult() {cout << best << "\n";}

    inline void printColors() {rep(i, 1, n) cout << bestColor[i] << " ";}

    ~DFS() {}

private:
    int n, m;
    vector<int> edges[MAXN];
    int best = MAXN;
    vector<int> bestColor;
    int color[MAXN];
};



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m; cin >> n >> m;

    DFS solver{n, m};
    
    solver.dfs(1, 0);

    solver.printBestResult();
    solver.printColors();

    return 0;
}

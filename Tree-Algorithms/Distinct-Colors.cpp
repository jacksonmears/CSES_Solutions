#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
 


set<int>* dfs(const int u, const int p, const vi& color, const vvi& edges, vi& ans) {
    set<int>* myset = new set<int>();
    myset->insert(color[u]);

    for (int v : edges[u]) {
        if (v == p) continue;
        set<int>* child = dfs(v, u, color, edges, ans);

        if (child->size() > myset->size()) swap(child, myset);
        myset->insert(child->begin(), child->end());
        delete child;
    }

    ans[u] = myset->size();
    return myset;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    vi color(n+1);
    vvi edges(n+1, vi{});
    vi ans(n+1);

    rep(i, 1, n) 
        cin >> color[i];

    rep(i, 0, n-2) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    set<int>* rootset = dfs(1, -1, color, edges, ans);
    delete rootset;

    rep(i, 1, n)
        cout << ans[i] << " ";

    return 0;
}
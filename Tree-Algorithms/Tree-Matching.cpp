#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<bool> vb;
typedef vector<pl> vp;
typedef vector<vl> vvl;
constexpr ll MAX = 9e18;
constexpr ll MOD = 1e9 + 7;
constexpr int MAXN = 2e5+1;

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (ll i = a; i <= b; i++)


vvl tree;
vb matched;

ll dfs(const ll node, const ll parent) {
    ll matches = 0;
    for (const ll child : tree[node]) {
        if (child == parent) continue;
        matches += dfs(child, node);
    }

    for (const ll child : tree[node]) {
        if (child == parent) continue;
        if (!matched[node] && !matched[child]) {
            matched[node] = matched[child] = true;
            matches++;
            break;
        }
    }
    return matches;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n; cin >> n;
    tree = vector(n+1, vl());
    matched = vector(n+1, false);

    rep(i, 0, n-2) {
        ll a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    cout << dfs(1, -1) << "\n";

    return 0;
}




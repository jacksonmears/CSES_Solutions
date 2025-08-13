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
#define repr(i, a, b) for (ll i = a; i >= b; i--)

ll n;
vl depth;
vvl tree;
bool seen[MAXN];
vvl binary_lifting;
const ll LOG = 20;

void fill_depth(ll const node, const ll current_depth) {
    for (const ll child : tree[node]) {
        if (child == node || seen[child]) continue;
        seen[child] = true;
        binary_lifting[child][0] = node;
        depth[child] = current_depth;
        fill_depth(child, current_depth+1);
    }
}


ll least_common_ancestor(ll a, ll b) {
    if (depth[a] < depth[b]) swap(a, b);
    repr(i, LOG-1, 0) {
        if ((depth[a]-depth[b]) & (1 << i)) a = binary_lifting[a][i];
    }

    if (a == b) return a;

    repr(i, LOG-1, 0) {
        if (binary_lifting[a][i] != binary_lifting[b][i]) {
            a = binary_lifting[a][i];
            b = binary_lifting[b][i];
        }
    }
    return binary_lifting[a][0];
}



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll q; cin >> n >> q;
    tree = vvl(n+1);
    depth = vl(n+1);
    binary_lifting = vector(n+1, vl(LOG, 0));
    rep(i, 0, n-2) {
        ll a, b; cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    seen[1] = true;
    fill_depth(1, 1);

    rep(i, 1, LOG) {
        rep(node, 1, n) {
            binary_lifting[node][i] = binary_lifting[binary_lifting[node][i-1]][i-1];
        }
    }

    rep(i, 0, q-1) {
        ll a, b; cin >> a >> b;
        ll lca = least_common_ancestor(a, b);


        cout << depth[a] + depth[b] - 2*depth[lca] << "\n";
    }

    return 0;
}




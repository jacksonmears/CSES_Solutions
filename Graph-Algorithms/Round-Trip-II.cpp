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

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (ll i = a; i <= b; i++)
#define repr(i, a, b) for (ll i = a; i >= b; i--)

ll n, m;
vvl flights;
vvl cycles;
ll seen[MAXN];
ll parents[MAXN];
ll found;

bool dfs(const ll& node) {
    seen[node] = 1;
    for (const ll child : flights[node]) {
        if (seen[child] == 0) {
            parents[child] = node;
            if (dfs(child)) return true;
        } else if (seen[child] == 1) {
            found = child;
            parents[child] = node;
            return true;
        }
    }
    seen[node] = 2;
    return false;

}



void fill_found_cycle(vl& cycle, ll& node) {
    while (node != found) {
        cycle.pb(node);
        node = parents[node];
    }
    cycle.pb(found);
}



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    flights = vvl(n+1);
    rep(i, 0, m-1) {
        ll a, b; cin >> a >> b;
        flights[a].pb(b);
    }


    rep(node, 1, n) {
        if (!seen[node] && dfs(node)) {
            vl cycle;
            cycle.pb(found);

            fill_found_cycle(cycle, parents[found]);
            ranges::reverse(cycle);

            cout << cycle.size() << "\n";
            for (const auto i : cycle) cout << i << " ";
            return 0;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}


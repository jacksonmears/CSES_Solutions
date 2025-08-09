#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<bool> vb;
typedef vector<pl> vp;
constexpr ll MAX = 9e18;
constexpr ll MOD = 1e9 + 7;

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (ll i = a; i <= b; i++)




ll n, m;
vector<vp> adj_matrix;
vb seen;
vl path;


// eulerian circuits
void heirholzer(const ll node) {
    while (!adj_matrix[node].empty()) {
        auto [child, edgeID] = adj_matrix[node].back(); adj_matrix[node].pop_back();
        if (seen[edgeID]) continue; seen[edgeID] = true;
        heirholzer(child);
    }
    path.pb(node);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj_matrix = vector(n + 1, vp({}));
    seen = vector(m, false);
    vector degree(n + 1, 0);

    rep(i, 0, m - 1) {
        ll a, b; cin >> a >> b;
        adj_matrix[a].emplace_back(mp(b, i));
        adj_matrix[b].emplace_back(mp(a, i));
        degree[a]++; degree[b]++;
    }

    // necessary check. Eulerian circuits on undirected graph require each node to have even indegrees
    rep(i, 1, n) {
        if (degree[i] % 2 != 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    // another prereq for eulerian curcuit. check if graph is disconnected
    vector visited(n + 1, false);
    stack<ll> street; street.push(1);
    visited[1] = true;
    while (!street.empty()) {
        const ll node = street.top(); street.pop();
        for (auto &[child, _] : adj_matrix[node]) {
            if (!visited[child]) {
                visited[child] = true;
                street.push(child);
            }
        }
    }

    // has edges but wasn't visited
    rep(i, 1, n) {
        if (degree[i] > 0 && !visited[i]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }



    heirholzer(1);

    for (const ll node : path) cout << node << " ";
    cout << "\n";
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
constexpr ll MAX = 9e18;
constexpr ll MOD = 1e9 + 7;

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (ll i = a; i <= b; i++)




ll n, m;
vector<vector<pl>> adj_matrix;
vector<bool> seen;
vl path;

void dfs(const ll node) {
    while (!adj_matrix[node].empty()) {
        auto [child, index] = adj_matrix[node].back();
        adj_matrix[node].pop_back();
        if (seen[index]) continue;
        seen[index] = true;
        dfs(child);
    }
    path.pb(node);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj_matrix = vector(n + 1, vector<pl>({}));
    seen = vector(m, false);
    vector degree(n + 1, 0);

    rep(i, 0, m - 1) {
        ll a, b; cin >> a >> b;
        adj_matrix[a].emplace_back(mp(b, i));
        adj_matrix[b].emplace_back(mp(a, i));
        degree[a]++; degree[b]++;
    }

    rep(i, 1, n) {
        if (degree[i] % 2 != 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    vector visited(n + 1, false);
    stack<ll> st; st.push(1);
    visited[1] = true;
    while (!st.empty()) {
        const ll node = st.top(); st.pop();
        for (auto &[child, _] : adj_matrix[node]) {
            if (!visited[child]) {
                visited[child] = true;
                st.push(child);
            }
        }
    }
    rep(i, 1, n) {
        if (degree[i] > 0 && !visited[i]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    dfs(1);

    if (static_cast<ll>(path.size()) != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    ranges::reverse(path);
    for (const ll node : path) cout << node << " ";
    cout << "\n";
}

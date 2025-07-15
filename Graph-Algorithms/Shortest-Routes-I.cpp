#include <bits/stdc++.h>
#include <regex>
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




int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n, m; cin >> n >> m;
    vector<vector<pl>> adjacency_matrix(n+1);
    rep(i, 0, m-1) {
        ll a, b, c; cin >> a >> b >> c;
        adjacency_matrix[a].pb({b, c});
    }


    priority_queue<pl, vector<pl>, greater<pl>> pq; pq.push({0,1});
    vl weights(n+1, LLONG_MAX); weights[1] = 0;
    while (!pq.empty()) {
        auto [distance, node] = pq.top(); pq.pop();
        if (distance > weights[node]) continue;
        for (auto child : adjacency_matrix[node]) {
            if (weights[child.first] > weights[node]+child.second) {
                weights[child.first] = weights[node] + child.second;
                pq.push({child.second+distance, child.first});
            }
        }
    }

    rep(i, 1, n) cout << weights[i] << " ";

    return 0;
}

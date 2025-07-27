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

const ll MAXN = 2e5+5;
vl adj_matrix[MAXN];
ll subtree_size[MAXN];
ll sum_of_distances[MAXN];
ll n;


void dfs1 (ll node, ll parent) {
    subtree_size[node] = 1;
    for (ll child : adj_matrix[node]) {
        if (child == parent) continue;
        dfs1(child, node);
        subtree_size[node] += subtree_size[child];
        sum_of_distances[node] += sum_of_distances[child] + subtree_size[child];
    }
}


void dfs2(ll node, ll parent) {
    for (ll child : adj_matrix[node]) {
        if (child == parent) continue;
        sum_of_distances[child] = sum_of_distances[node] - subtree_size[child] + (n - subtree_size[child]);
        dfs2(child, node);
    }
}



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    rep(i, 0, n-2) {
        ll a, b; cin >> a >> b;
        adj_matrix[a].pb(b); adj_matrix[b].pb(a);
    }

    dfs1(1, 0);
    dfs2(1, 0);

    rep(i, 1, n) cout << sum_of_distances[i] << " ";

    return 0;
}

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

    ll n, q; cin >> n >> q;
    ll log_n = (ll)log2(n);

    vector<vl> sparse_table(log_n + 1, vl(n));
    rep(i, 0, n-1) cin >> sparse_table[0][i];

    rep(i, 1, log_n) {
        ll length = 1LL << i;
        ll half = length >> 1;
        for (ll j = 0; j + length <= n; j++) {
            sparse_table[i][j] = min(sparse_table[i-1][j], sparse_table[i-1][j + half]);
        }
    }

    while (q--) {
        ll a, b; cin >> a >> b; a--; b--;
        ll log_q = (ll)log2(b-a+1);
        cout << min(sparse_table[log_q][a], sparse_table[log_q][b-(1<<log_q)+1]) << "\n";
    }

    return 0;
}

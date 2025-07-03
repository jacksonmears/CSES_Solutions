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

    ll n, m, q; cin >> n >> m >> q;
    vector<vl> floyd_warshall(n+1, vl(n+1, LLONG_MAX));
    rep(i, 0, m-1) {
        ll a, b, c; cin >> a >> b >> c;
        floyd_warshall[a][b] = min(floyd_warshall[a][b], c);
        floyd_warshall[b][a] = min(floyd_warshall[b][a], c);
    }
    rep(i, 1, n) floyd_warshall[i][i] = 0;


    rep(k, 1, n) {
        rep(i, 1, n) {
            rep(j, 0, n) {
                if (floyd_warshall[i][k] != LLONG_MAX && floyd_warshall[k][j] != LLONG_MAX) {
                    floyd_warshall[i][j] = min(floyd_warshall[i][j], floyd_warshall[i][k] + floyd_warshall[k][j]);
                }
            }
        }
    }

    rep(i, 0, q-1) {
        ll a, b; cin >> a >> b;
        (floyd_warshall[a][b] == LLONG_MAX) ? cout << "-1\n" : cout << floyd_warshall[a][b] << "\n";
    }







    return 0;
}

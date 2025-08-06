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

ll n;

vector<pl> check = {{-1,0}, {0, -1}, {-1,-1}};
bool in_bounds(const ll& x, const ll& y) {
    return x < n && x >= 0 && y < n && y >= 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll k; cin >> n >> k;
    vl letter_count(k, 0);
    vector<string> grid(n);
    vector grid_count(n, vl(n, 1));

    rep(i, 0, n-1) {
        cin >> grid[i];
    }

    rep(x, 0, n-1) {
        rep(y, 0, n-1) {
            ll mn = LLONG_MAX;
            for (auto &[dx, dy] : check) {
                const ll nx = x+dx, ny = y+dy;
                if (!in_bounds(nx, ny) || grid[x][y] != grid[nx][ny]) {
                    mn = 0;
                }
                else mn = min(mn, grid_count[nx][ny]);
            }
            grid_count[x][y] += mn;
            letter_count[grid[x][y]-'A'] += grid_count[x][y];
        }
    }



    for (auto i : letter_count) cout << i << "\n";


    return 0;
}

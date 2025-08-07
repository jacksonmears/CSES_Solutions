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



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n, k; cin >> n >> k;
    vl letter_count(k, 0);
    vector<string> grid(n);
    vector horizontal_count(n, vl(n, 1));

    rep(i, 0, n-1) {
        cin >> grid[i];
    }

    rep(x, 0, n-1) {
        rep(y, 0, n-1) {
            if (y > 0 && grid[x][y] == grid[x][y-1])
                horizontal_count[x][y] = horizontal_count[x][y-1] + 1;

            ll mn = horizontal_count[x][y];
            for (ll iterator = x; iterator >= 0; --iterator) {
                if (grid[iterator][y] != grid[x][y]) break;
                mn = min(mn, horizontal_count[iterator][y]);
                letter_count[grid[x][y] - 'A'] += mn;
            }
        }
    }


    for (const auto count : letter_count)
        cout << count << '\n';

    return 0;
}


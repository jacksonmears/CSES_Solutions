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
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)




int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll n, m; cin >> n >> m;
    vl numbers(n), position(n+2);

    REP(i, 0, n-1) {
        cin >> numbers[i];
        position[numbers[i]] = i;
    }

    ll rounds = 1;
    REP(i, 2, n) if (position[i] < position[i - 1]) rounds++;

    while (m--) {
        ll a, b; cin >> a >> b;
        a--; b--;

        ll x = numbers[a], y = numbers[b];
        if (x == y) {
            cout << rounds << '\n';
            continue;
        }

        set<ll> affected;
        for (ll val : {x - 1, x, x + 1, y - 1, y, y + 1}) {
            if (val >= 1 && val <= n) affected.insert(val);
        }

        for (ll i : affected) {
            if (i > 1 && position[i] < position[i - 1]) rounds--;
        }

        swap(numbers[a], numbers[b]);
        swap(position[x], position[y]);

        for (ll i : affected) {
            if (i > 1 && position[i] < position[i - 1]) rounds++;
        }

        cout << rounds << '\n';
    }

    return 0;
}

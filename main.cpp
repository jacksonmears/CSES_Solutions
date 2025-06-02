#include <bits/stdc++.h>
#include <regex>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
constexpr ll MAX = 9e18;
constexpr ll MOD = 1e9 + 7;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)


ll gcd(ll a, ll b) {
    while (b) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n; vl v(n);
        ll g = 0;
        REP(i, 0, n-1) {
            cin >> v[i];
            g = (i == 0) ? v[i] : gcd(g, v[i]);
        }

        int mn = INT_MAX;
        for (int i = 0; i < n; ++i) {
            ll cg = 0;
            for (int j = i; j < n; ++j) {
                cg = gcd(cg, v[j]);
                if (cg == g) {
                    mn = min(mn, j - i + 1);
                    break;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i) if (v[i] == g) ++cnt;

        if (mn == INT_MAX) mn = n;


        (cnt > 0) ? cout << (n - cnt) << '\n' : cout << n + mn - 2 << '\n';
    }
    return 0;
}
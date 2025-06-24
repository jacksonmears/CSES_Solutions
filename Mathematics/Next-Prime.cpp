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
#define REP(i,a,b) for (ll i = a; i <= b; i++)


bool is_prime(ll x) {
    if (x == 2) return true;
    if (x < 2 || x%2 == 0) return false;
    for (ll i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}


void solve() {
    ll n; cin >> n;
    ll currentN = n + 1;
    while (!is_prime(currentN)) currentN++;
    cout << currentN << "\n";
}



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

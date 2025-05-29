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


void solve(const ll& y, const ll& x) {

    if (x >= y) {
        if (x&1) cout << x * x - y + 1 << '\n';
        else cout << (x - 1) * (x - 1) + 1 + y - 1 << '\n';
    } else {
        if (!(y&1)) cout << y * y - x + 1 << '\n';
        else cout << (y - 1) * (y - 1) + 1 + x - 1 << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);


    ll t; cin >> t;
    while (t--) {
        ll y, x; cin >> y >> x;
        solve(y, x);
    }


    return 0;
}
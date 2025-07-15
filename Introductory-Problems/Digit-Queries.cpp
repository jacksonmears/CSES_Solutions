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


void solve() {
    ll k; cin >> k;

    ll len = 1;
    ll total = 9;

    while (k > total * len) {
        k -= total * len;
        len++;
        total *= 10;
    }

    ll start = pow(10, len - 1);
    ll numberIndex = (k - 1) / len;
    ll digitIndex = (k - 1) % len;

    ll number = start + numberIndex;
    string s = to_string(number);

    cout << s[digitIndex] << '\n';
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll q; cin >> q;
    while (q--) {
        solve();
    }


    return 0;
}
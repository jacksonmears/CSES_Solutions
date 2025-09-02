#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
constexpr int MOD = 1e9 + 7;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = a; i >= b; --i)


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

    int q; cin >> q;
    while (q--) {
        solve();
    }


    return 0;
}
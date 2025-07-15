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


void handleSmall (const ll &n) {
    for (ll i = n; i > 0; i--) cout << i << ' ';
    cout << '\n';
}

void handleBig (ll n, const ll a, const ll b) {
    while (n > a+b) {
        cout << n << ' ';
        n--;
    }
    for (ll i = 1; i <= b; i++) {
        cout << i << ' ';
    }
    for (ll i = n; i > b; i--) {
        cout << i << ' ';
    }
    cout << '\n';
}


void solve(const ll &n, const ll&a, const ll&b) {
    if(a+b<=n && ((a==b && a==0) || (max(a,b) > 0 && min(a,b) > 0))) {
        cout << "YES" << endl;
        if (a<=b) {
            handleSmall(n);
            handleBig(n, max(a,b), min(a,b));
        } else {
            handleBig(n, max(a,b), min(a,b));
            handleSmall(n);
        }
    }
    else cout << "NO" << endl;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll t; cin >> t;
    while (t--) {
        ll n, a , b; cin >> n >> a >> b;
        solve(n,a,b);
    }





    return 0;
}
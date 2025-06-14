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

const int MAXN = 10e6+5;

ll a[MAXN], b[MAXN];

void buildDP() {
    a[1] = 1; b[1] = 1;
    REP(i, 2, MAXN-1) {
        a[i] = (2 * a[i - 1] % MOD + b[i - 1]) % MOD;
        b[i] = (4 * b[i - 1] % MOD + a[i - 1]) % MOD;
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    buildDP();

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        cout << (a[n] + b[n]) % MOD << "\n";
    }


    return 0;
}
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


const int MAXN = 1e6 + 5;

ll factorial[MAXN];
ll invFactorial[MAXN];

ll modPow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void precompute() {
    factorial[0] = invFactorial[0] = 1;
    rep(i, 1, MAXN - 1)
        factorial[i] = factorial[i - 1] * i % MOD;

    invFactorial[MAXN - 1] = modPow(factorial[MAXN - 1], MOD - 2, MOD);
    for (int i = MAXN - 2; i >= 1; --i)
        invFactorial[i] = invFactorial[i + 1] * (i + 1) % MOD;
}


ll binomial(ll a, ll b) {
    if (b < 0 || b > a) return 0;
    return factorial[a] * invFactorial[b] % MOD * invFactorial[a - b] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    precompute();

    while (n--) {
        ll a, b;
        cin >> a >> b;
        cout << binomial(a, b) << "\n";
    }

    return 0;
}

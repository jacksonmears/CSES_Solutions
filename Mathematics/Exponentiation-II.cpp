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


// binary exponentiation
ll calPow(ll base, ll exponent)
{
    if (exponent == 0) return 1;
    if (exponent == 1) return base % MOD;

    ll temp = calPow(base, exponent / 2);
    if (exponent % 2 == 0) return (temp * temp) % MOD;

    return (((temp * temp) % MOD) * base) % MOD;
}



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll t; cin >> t;
    while (t--) {
        ll a, b, c; cin >> a >> b >> c;
        cout << calPow(a, calPow(b, c)) << "\n";
    }

    return 0;
}

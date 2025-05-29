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


// calculating exponent with binary
ll binpow(ll a, ll& b) {
    ll result = 1;
    a %= MOD;
    while (b) {
        if (b&1) result = result * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    // this solution is much easier/simpler in python due to the way python handles large numbers via strings


    ll n; cin >> n;

    cout << binpow(2, n);


    return 0;
}
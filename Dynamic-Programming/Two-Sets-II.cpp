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



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll n; cin >> n;
    ll targetValue = n * (n + 1) / 2;
    if (targetValue & 1) return cout << 0, 0;

    targetValue /= 2;
    vl dp(targetValue + 1, 0); dp[0] = 1;

    REP(current, 1, n) {
        for (ll sum = targetValue; sum >= current; sum--) {
            dp[sum] = (dp[sum] + dp[sum - current]) % MOD;
        }
    }

    ll inverse_of_2 = (MOD + 1) / 2;
    cout << (dp[targetValue] * inverse_of_2) % MOD << "\n";

    return 0;
}

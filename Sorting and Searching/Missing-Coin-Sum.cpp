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

    ll n; cin >> n; vl coins(n);
    REP(i, 0, n-1) cin >> coins[i];
    ranges::sort(coins); ll totalSumOfPreviousCoins = 0;
    REP(i, 0, n-1) {
        if (coins[i] > totalSumOfPreviousCoins+1) return cout << totalSumOfPreviousCoins+1, 0;
        totalSumOfPreviousCoins += coins[i];
    }

    cout << totalSumOfPreviousCoins+1;

    return 0;
}

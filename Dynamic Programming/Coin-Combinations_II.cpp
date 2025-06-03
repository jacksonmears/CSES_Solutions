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
    ios::sync_with_stdio(false);cin.tie(nullptr);

    ll n, x; cin >> n >> x;
    vector<ll> coins(n); REP(i, 0, n-1) cin >> coins[i];
    vector<ll> dynamicProgramming(x+1, 0); dynamicProgramming[0] = 1;
    // do coins in order to x that way you can't do 3+2 because once you do 2+x the two is stuck in first position forever.
    REP(i, 0, n-1) {
        ll coin = coins[i];
        REP(sum, coin, x) {
            dynamicProgramming[sum] = (dynamicProgramming[sum] + dynamicProgramming[sum - coin]) % MOD;
        }
    }

    cout << dynamicProgramming[x] << "\n";
    return 0;
}

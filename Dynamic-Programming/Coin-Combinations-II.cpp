#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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


constexpr int MAXN = 1e6+1;
ll n, x, dp[MAXN], coin;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);

    cin >> n >> x;
    vl coins(n); 
    rep(i, 0, n-1) 
        cin >> coins[i];

    // do each coin individually (not explicitly in order but cses doesn't need to know that)
    dp[0] = 1;
    for (ll coin : coins) {
        rep(i, coin, x) {
            dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
    }

    cout << dp[x] << "\n";
    return 0;
}

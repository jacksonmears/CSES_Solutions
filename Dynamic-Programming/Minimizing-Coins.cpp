
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
 
 
constexpr int MAXN = 1e6;
int n, x, dp[MAXN];
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
 

    cin >> n >> x;
    vi coins(n);
    rep(i, 0, n-1) {
        cin >> coins[i];
    }

    fill(dp, dp + x+1, INT_MAX);
    dp[0] = 0;
    rep(i, 0, x+1) if (dp[i] != INT_MAX) {
        for (auto coin : coins) {
            if (i + coin > x+1) continue;
            dp[i + coin] = min(dp[i + coin], dp[i] + 1);
        }
    }

    cout << (dp[x] == INT_MAX ? -1 : dp[x]);
    

    return 0;
}

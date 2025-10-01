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
typedef vector<char> vc;
constexpr int MOD = 1e9 + 7;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i = a; i <= b; ++i)
 
 
constexpr int MAXN = 1001;
char grid[MAXN][MAXN];
int dp[MAXN][MAXN];
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
    int n; cin >> n;
    dp[0][0] = 1;
 
    rep(i, 0, n-1) {
        rep(j, 0, n-1) cin >> grid[i][j];
    }
 
    rep(row, 0, n-1) {
        rep(col, 0, n-1) {
            if (grid[row][col] == '*') {
                dp[row][col] = 0;
                continue;
            }
            if (row) dp[row][col] = (dp[row][col] + dp[row - 1][col]) % MOD;
            if (col) dp[row][col] = (dp[row][col] + dp[row][col - 1]) % MOD;
        }
    }
 
    cout << dp[n - 1][n - 1] << "\n";
 
 
 
    return 0;
}
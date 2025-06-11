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

    ll a, b; cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));

    REP(width, 1, a) {
        REP(height, 1, b) {
            if (width == height) {
                dp[width][height] = 0;
            } else {
                REP(horizontalCutLine, 1, width-1) {
                    dp[width][height] = min(dp[width][height], dp[horizontalCutLine][height] + dp[width - horizontalCutLine][height] + 1);
                }
                REP(verticalCutLine, 1, height-1) {
                    dp[width][height] = min(dp[width][height], dp[width][verticalCutLine] + dp[width][height - verticalCutLine] + 1);
                }
            }
        }
    }

    cout << dp[a][b] << "\n";
    return 0;
}

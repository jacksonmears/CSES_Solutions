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

    ll n, m; cin >> n >> m;
    vi a(n), b(m);
    REP(i, 0, n-1) cin >> a[i];
    REP(i, 0, m-1) cin >> b[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    REP(i, 1, n) {
        REP(j, 1, m) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    ll i = n, j = m;
    deque<ll> lcs;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs.push_front(a[i - 1]);
            --i; --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) --i;
        else --j;
    }

    cout << lcs.size() << '\n';
    for (int x : lcs)
        cout << x << ' ';
    cout << '\n';

    return 0;
}
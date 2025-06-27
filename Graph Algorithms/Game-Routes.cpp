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





int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n, m; cin >> n >> m;
    vector<vl> adjacency(n + 1);
    vl inDegrees(n + 1, 0);

    REP(i, 0, m - 1) {
        ll a, b; cin >> a >> b;
        adjacency[a].pb(b);
        inDegrees[b]++;
    }

    queue<ll> q;
    vl dp(n + 1, 0);
    dp[1] = 1;

    REP(i, 1, n) if (inDegrees[i] == 0) q.push(i);


    while (!q.empty()) {
        ll node = q.front(); q.pop();
        for (ll next : adjacency[node]) {
            dp[next] = (dp[next] + dp[node]) % MOD;
            inDegrees[next]--;
            if (inDegrees[next] == 0) q.push(next);
        }
    }

    cout << dp[n] << '\n';

    return 0;
}


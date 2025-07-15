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
#define rep(i,a,b) for (ll i = a; i <= b; i++)




int main() {
    	ios::sync_with_stdio(false); cin.tie(nullptr);

	ll n, m; cin >> n >> m;
	vl elements(n); rep(i, 0, n-1) cin >> elements[i];
	
	vector<vl> dp(n, vl(m+2, 0)); 
	if(elements[0]) dp[0][elements[0]] = 1;
	else rep(i, 1, m) dp[0][i] = 1;	
	rep(i, 1, n-1) {
		ll v = elements[i];
		if(v) {
			dp[i][v] = (dp[i-1][v-1] + dp[i-1][v] + dp[i-1][v+1]) % MOD;		
		}
		else {
			rep(j, 1, m) dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD;
		}
		for (auto k : dp[i]) cout << k << " ";
		cout << endl;
	}
	
	
	ll total = 0;
	for (auto i : dp[n-1]) total = (total + i) % MOD;
	cout << total;


    return 0;
}



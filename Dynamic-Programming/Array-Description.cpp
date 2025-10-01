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
#define repr(i, a, b) for (int i = a; i >= b; --i)



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, m; cin >> n >> m;
	vi elements(n); 
	rep(i, 0, n-1) 
		cin >> elements[i];
	
	vl prev(m+2, 0), cur(m+2, 0);

	if (elements[0]) {
		prev[elements[0]] = 1;
	} else {
		rep(i, 1, m) 
			prev[i] = 1;
	}

	rep(i, 1, n-1) {
		fill(cur.begin(), cur.end(), 0);
		int x = elements[i];
		if (x) {
			cur[x] = (prev[x-1] + prev[x] + prev[x+1]) % MOD;
		} else {
			rep(j, 1, m) 
				cur[j] = (prev[j-1] + prev[j] + prev[j+1]) % MOD;
		}
		swap(prev, cur);
	}

	ll ans = 0;
	rep(i, 1, m)
		ans = (ans + prev[i]) % MOD;
	cout << ans << "\n";


    return 0;
}



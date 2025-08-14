#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<bool> vb;
typedef vector<pl> vp;
typedef vector<vl> vvl;
constexpr ll MAX = 9e18;
constexpr ll MOD = 1e9 + 7;
constexpr int MAXN = 2e5+1;

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (ll i = a; i <= b; i++)
#define repr(i, a, b) for (ll i = a; i >= b; i--)

map<pl, ll> m;


ll solve(ll k, ll n){
    if(m[mp(k, n)])   return m[mp(k, n)];

    if(k == 1) return m[mp(k, n)] = 1;
    if(2*n <= k) return m[mp(k, n)] = 2*n;

    const ll tempK = (k/2)+(k&1);
    const ll tempN = n-k/2;

    if(k&1){
        const ll output = solve(tempK, tempN);
        return m[mp(k, n)] = ((2*output-3)+(k+1)) % (k+1);
    }

    return m[mp(k, n)] = 2*solve(tempK, tempN)-1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll q; cin >> q;
    while (q--) {
        ll k, n; cin >> k >> n;
        cout << solve(k, n) << "\n";
    }


    return 0;
}




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

    ll n; cin >> n;
    vl dp;
    rep(i, 0, n-1) {
        ll x; cin >> x;
        auto low_iterator = lower_bound(dp.begin(), dp.end(), x);
        if (low_iterator == dp.end()) dp.pb(x);
        else *low_iterator = x;
    }

    cout << dp.size();





    return 0;
}

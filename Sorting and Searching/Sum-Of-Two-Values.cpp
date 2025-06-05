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

    ll n, x; cin >> n >> x;
    map<ll,ll> seenValues;
    REP(i, 0, n-1) {
        ll a; cin >> a;
        if (seenValues.contains(x-a)) {
            return cout << seenValues[x-a]+1 << " " << i+1, 0;
        }
        seenValues[a] = i;
    }

    cout << "IMPOSSIBLE";

    return 0;
}

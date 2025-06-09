#include <bits/stdc++.h>
#include <regex>
using namespace std;
typedef long long ll;
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

    ll n; cin >> n;
    vl dynamicPrograming; dynamicPrograming.push_back(0);
    set<ll> seen;
    REP(i, 0, n-1) {
        ll x; cin >> x;
        size_t lengthOfDP = dynamicPrograming.size()-1;
        REP(j, 0, lengthOfDP) {
            ll newValue = x+dynamicPrograming[j];
            if (!seen.contains(newValue)) {
                dynamicPrograming.push_back(newValue);
                seen.insert(newValue);
            }
        }
    }

    cout << seen.size() << "\n";
    for (auto i : seen) {
        cout << i << ' ';
    }

    return 0;
}

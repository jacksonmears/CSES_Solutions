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

    ll n; cin >> n;
    vl songs(n);
    REP(i, 0, n-1) cin >> songs[i];

    set<ll> seen;
    ll left = 0, maximumUniqueSubarrayLength = 0;

    REP(right, 0, n-1) {
        while (seen.count(songs[right])) {
            seen.erase(songs[left]);
            left++;
        }
        seen.insert(songs[right]);
        maximumUniqueSubarrayLength = max(maximumUniqueSubarrayLength, right - left + 1);
    }

    cout << maximumUniqueSubarrayLength << '\n';


    return 0;
}

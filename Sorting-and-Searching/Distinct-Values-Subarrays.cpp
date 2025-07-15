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
    unordered_map<ll, ll> lastSeen;
    ll left = 0, totalDistinctSubarrays = 0;

    REP(right, 0, n - 1) {
        ll x; cin >> x;
        if (lastSeen.count(x)) left = max(left, lastSeen[x] + 1);
        lastSeen[x] = right;
        totalDistinctSubarrays += right - left + 1;
    }

    cout << totalDistinctSubarrays;


    return 0;
}

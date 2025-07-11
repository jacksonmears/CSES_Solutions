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

    ll n, target; cin >> n >> target;
    vector<ll> elements(n);
    rep(i, 0, n-1) cin >> elements[i];

    vector<pair<ll, pl>> pair_sums;
    rep(i, 0, n-1) {
        rep(j, i+1, n-1) {
            pair_sums.push_back({elements[i] + elements[j], {i, j}});
        }
    }

    unordered_map<ll, vector<pl>> seen;
    for (auto &[sum, p1] : pair_sums) {
        ll need = target - sum;
        if (seen.count(need)) {
            for (auto &[i2, j2] : seen[need]) {
                if (p1.first != i2 && p1.first != j2 && p1.second != i2 && p1.second != j2) {
                    return cout << p1.first+1 << " " << p1.second+1 << " " << i2+1 << " " << j2+1, 0;
                }
            }
        }
        seen[sum].push_back(p1);
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}



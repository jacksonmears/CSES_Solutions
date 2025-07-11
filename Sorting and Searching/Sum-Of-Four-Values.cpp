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
    vector<pl> elements(n);
    rep(i, 0, n-1) {
        ll x; cin >> x;
        elements[i] = {x, i+1};
    }
    ranges::sort(elements);

    rep(i, 0, n-1) {
        if (i > 0 && elements[i].first == elements[i-1].first) continue;
        rep(j, i+1, n-1) {
            if (j > i+1 && elements[j].first == elements[j-1].first) continue;
            rep(k, j+1, n-1) {
                ll need = target - elements[i].first - elements[j].first - elements[k].first;
                auto it = lower_bound(elements.begin()+k+1, elements.end(), mp(need, 0ll));
                if (it->second <= n && it->first==need) return cout << elements[i].second << " " << elements[j].second << " " << elements[k].second << " " << it->second, 0;
            }
        }
    }


    cout << "IMPOSSIBLE";

    return 0;
}

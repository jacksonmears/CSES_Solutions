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



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);


    ll n, k; cin >> n >> k;
    vl elements(n); rep(i, 0, n-1) cin >> elements[i];
    ranges::sort(elements);

    multiset<ll> smallestK; smallestK.insert(0);
    vl storage; storage.pb(0);

    ll current_element = 0;
    ll k_counter = 0;
    while (current_element < elements.size() && k_counter < k) {
        const size_t s = storage.size()-1;
        repr(j, s, 0) {
            ll x = storage[j]+elements[current_element];
            smallestK.insert(x);
            storage.pb(x);
            k_counter++;
        }
        current_element++;
    }


    auto it = smallestK.begin();
    k_counter = 0;
    while (it != smallestK.end() && k_counter < k) {
        cout << *it << " ";
        it++;
        k_counter++;
    }


    return 0;
}


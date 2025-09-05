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


#include <ext/pb_ds/assoc_container.hpp> #
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


// solution comes from https://github.com/Jonathan-Uy they're a genius fr fr I couldn't figure this one out

int n;
ll k;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> k;

    ordered_set people;
    rep(i, 1, n) 
        people.insert(i);


    ll index = k % n; // current position in 0-based order
    while (!people.empty()) {
        auto it = people.find_by_order(index);
        cout << *it << " ";
        people.erase(it);
        if (!people.empty()) 
            index = (index + k) % people.size();
    }


    return 0;
}

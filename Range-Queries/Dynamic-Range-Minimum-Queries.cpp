#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<bool> vb;
typedef vector<pl> vp;
constexpr ll MAX = 9e18;
constexpr ll MOD = 1e9 + 7;

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (ll i = a; i <= b; i++)


ll n;
vl segment_tree;

void update_tree(ll index, const ll new_value) {
    index += n - 1;
    segment_tree[index] = new_value;
    for (index /= 2; index >= 1; index /= 2) {
        segment_tree[index] = min(segment_tree[index * 2], segment_tree[index * 2 + 1]);
    }
}


void query_tree (ll a, ll b) {
    a += n-1; b += n-1;
    ll mn = LLONG_MAX;
    while (a <= b) {
        if (a&1) mn = min(mn, segment_tree[a++]);
        if (!(b&1)) mn = min(mn, segment_tree[b--]);
        a /= 2; b /= 2;
    }
    cout << mn << "\n";
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll q; cin >> n >> q;
    segment_tree = vl(n*2);
    rep(i, n, n*2-1) cin >> segment_tree[i];
    for (ll i = n-1; i >= 1; i--) {
        segment_tree[i] = min(segment_tree[i * 2], segment_tree[i * 2 + 1]);
    }

    rep(i, 0, q-1) {
        ll k, a, b; cin >> k >> a >> b;
        if (k&1) update_tree(a, b);
        else query_tree(a, b);
    }


   return 0;
}

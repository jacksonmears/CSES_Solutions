#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
constexpr int MOD = 1e9 + 7;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = a; i >= b; --i)
 
 
constexpr int MAXN = 2e5+1;
ll x;
vl basis;
int n, k;
vl subset_xors;

void insert_basis(ll x) {
    for (int b : basis) 
        x = std::min(x, x ^ b);
    
    if (x) basis.pb(x);
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    cin >> n >> k;
    basis.reserve(32); 
 
    rep(i, 0, n-1) {
        cin >> x;
        insert_basis(x);
    }

    // multiplicity is enormous, definitely >= k and 2^18 > 2e5 which is max of k.
    if (n - (int)basis.size() >= 18) {
        rep(i, 1, k) cout << 0 << " ";
        return 0;
    }
    sort(basis.begin(), basis.end());
 
    subset_xors.reserve(MAXN);
    subset_xors.pb(0);
    for (ll b : basis) {
        int sz = subset_xors.size();
        if (sz * (1 << (n-basis.size())) > k) break; // limit growth to avoid runtime errors when vector overflows with too many bytes
        rep(i, 0, sz-1)
            subset_xors.push_back(subset_xors[i] ^ b);
    }
 
 
 
    sort(subset_xors.begin(), subset_xors.end());
    ll r = 1 << (n - (int)basis.size());
    rep(i, 0, k-1) {
        cout << subset_xors[i / r] << " ";
    }
 
 
    return 0;
}  
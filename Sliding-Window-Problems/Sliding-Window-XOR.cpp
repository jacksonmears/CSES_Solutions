#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef vector<int32_t> vi;
typedef vector<vi> vvi;
typedef pair<int32_t, int32_t> pi;
typedef vector<pi> vpi;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef vector<char> vc;
constexpr int MOD = 1e9 + 7;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = a; i >= b; --i)
 




int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, k, x, a, b, c; cin >> n >> k >> x >> a >> b >> c;

    vl elements(n); elements[0] = x;
    ll ans = 0;
    rep(i, 1, n-1) {
        elements[i] = (a*elements[i-1] +b) % c;
        int t = k - max(0, k-i-1) - max(0, i-(n-k));
        if (t&1) ans ^= elements[i];
    }

    cout << (ans^elements[0]);






    
    return 0;
}
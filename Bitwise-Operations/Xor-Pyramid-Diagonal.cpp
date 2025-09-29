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
 


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n; cin >> n;
    int m = 1;
    while (m < n) m <<= 1; 

    vl ans(m, 0);
    rep(i, 0, n-1)
        cin >> ans[i];

    for (int bit = 0; (1<<bit) < m; bit++) {
        rep(mask, 0, m-1) {
            if (mask & (1<<bit)) 
                ans[mask] ^= ans[mask ^ (1<<bit)];
        }
    }

    rep(i, 0, n-1) 
        cout << ans[i] << " ";


    return 0;
}

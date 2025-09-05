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


int n;
ll t, prefix = 0, mx = 0;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    rep(i, 0, n-1) {
        cin >> t; 
        prefix += t;
        mx = max(mx, t);
    }

    cout << max(prefix, 2 * mx) << '\n';

    return 0;
}

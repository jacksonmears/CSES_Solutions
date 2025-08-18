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
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define repr(i, a, b) for (int i = a; i >= b; i--)


int LOG = 30;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector binary_lifting(n+1, vi(LOG));
    rep(i, 1, n) cin >> binary_lifting[i][0];

    rep(mask, 1, LOG-1) {
        rep(node, 1, n) {
            binary_lifting[node][mask] = binary_lifting[binary_lifting[node][mask-1]][mask-1];
        }
    }


    rep(i, 0, q-1) {
        int a, b; cin >> a >> b;
        rep(bit, 0, LOG-1) {
            if (b & (1 << bit))
                a = binary_lifting[a][bit];
        }
        cout << a << "\n";
    }



    return 0;
}


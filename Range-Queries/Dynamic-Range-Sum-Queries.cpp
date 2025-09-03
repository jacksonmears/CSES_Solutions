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


ll n, q, x, a, b;
vl fenwick;

void update(ll i, ll value) {
    while (i < fenwick.size()) {
        fenwick[i] += value;
        i += i & -i;
    }
}

ll query(ll i) {
    ll sum = 0;
    while (i > 0) {
        sum += fenwick[i];
        i -= i & -i;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> q;
    vl elements(n + 1);
    rep(i, 1, n)
        cin >> elements[i];

    fenwick.assign(n + 1, 0);

    rep(i, 1, n)
        update(i, elements[i]);

    rep(i, 0, q - 1) {
        cin >> x >> a >> b;
        if (x == 1) {
            update(a, -elements[a]);
            elements[a] = b;
            update(a, b);
        } else {
            if (a < b) swap(a, b); 
            cout << query(a) - query(b-1) << "\n";
        }
    }

    return 0;
}

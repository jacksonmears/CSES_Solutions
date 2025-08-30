
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



constexpr int MAXN = 2e5+1;
int original_values[MAXN];
ll fenwick[MAXN];
int n, q, t, a, b, u, k;

ll query (int node) {
    ll sum = 0;
    for (int i = node; i > 0; i -= i&-i) {
        sum += fenwick[i];
    }
    return sum;
}

void update(int start, ll value) {
    for (int i = start; i <= n; i += i&-i) {
        fenwick[i] += value;
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> q;
    rep(i, 1, n){
        cin >> original_values[i];
    }

    rep(i, 0, q-1) {
        cin >> t;
        if (t == 1) {
            cin >> a >> b >> u;
            update(a, u);
            update(b+1, -u);
        }
        else {
            cin >> k; 
            cout << original_values[k] + query(k) << "\n";
        }
    }



    return 0;
}


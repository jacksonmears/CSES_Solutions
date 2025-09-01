
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

int n, m, value, pad_n;
vi segment_tree;

int query(int node) {
    if (node >= pad_n) return node;
    if (segment_tree[node*2] >= value)
        return query(node*2);
    else
        return query(node*2+1);
}

void update(int node) {
    segment_tree[node] -= value;
    for (int i = node/2; i >= 1; i /= 2) {
        segment_tree[i] = max(segment_tree[i*2], segment_tree[i*2+1]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    pad_n = 1;
    while (pad_n < n) pad_n <<= 1;  // round up to next power of 2
    segment_tree.assign(pad_n*2, 0);

    rep(i, 0, n-1) {
        cin >> segment_tree[i + pad_n];
    }

    repr(i, pad_n-1, 1) {
        segment_tree[i] = max(segment_tree[i*2], segment_tree[i*2+1]);
    }

    rep(i, 0, m-1) {
        cin >> value;
        if (segment_tree[1] < value) {
            cout << 0 << " ";
            continue;
        }
        int node = query(1);
        cout << node - pad_n + 1 << " ";
        update(node);
    }

    return 0;
}


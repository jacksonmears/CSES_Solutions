
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


struct Node {
    ll sum, mx;
};

int n, q;
vector<Node> segment_tree;

Node merge(Node left, Node right) {
    Node result;
    result.sum = left.sum + right.sum;
    result.mx = max(left.mx, left.sum + right.mx);
    return result;
}

void build(vl& elements, int i, int left, int right) {
    if (left == right) {
        segment_tree[i].sum = elements[left];
        segment_tree[i].mx = max(elements[left], 0LL); 
        return;
    }
    int middle = (left + right) / 2;
    build(elements, i*2, left, middle);
    build(elements, i*2+1, middle+1, right);
    segment_tree[i] = merge(segment_tree[i*2], segment_tree[i*2+1]);
}

void update(int i, int left, int right, int position, ll value) {
    if (left == right) {
        segment_tree[i].sum = value;
        segment_tree[i].mx = max(value, 0LL);
        return;
    }
    int middle = (left + right) / 2;
    if (position <= middle) update(i*2, left, middle, position, value);
    else update(i*2+1, middle+1, right, position, value);
    segment_tree[i] = merge(segment_tree[i*2], segment_tree[i*2+1]);
}

Node query(int i, int left, int right, int qleft, int qright) {
    if (qright < left || right < qleft) return {0, LLONG_MIN}; 
    if (qleft <= left && right <= qright) return segment_tree[i];
    int middle = (left + right) / 2;
    Node L = query(i*2, left, middle, qleft, qright);
    Node R = query(i*2+1, middle+1, right, qleft, qright);
    if (L.mx == LLONG_MIN) return R;
    if (R.mx == LLONG_MIN) return L;
    return merge(L, R);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    vl elements(n+1);
    rep(i, 1, n) cin >> elements[i];

    segment_tree.assign(4*n, {0,0});
    build(elements, 1, 1, n);

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            update(1, 1, n, a, b);
        } else {
            Node res = query(1, 1, n, a, b);
            cout << res.mx << "\n";
        }
    }
}
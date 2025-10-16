#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

using vi = vector<int32_t>;
using vvi = vector<vi>;
using pi = pair<int32_t, int32_t>;
using vpi = vector<pi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using vb = vector<bool>;
using vc = vector<char>;

#define pb push_back
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define repr(i,a,b) for (int i = a; i >= b; --i)

constexpr uint32_t MOD = 1e9 + 7;


struct Node {
    ll sum = 0;     
    ll set_val = 0; 
    ll add_val = 0;   
};


void push(int node, int left, int right, vector<Node>& tree) {
    if (tree[node].set_val) {
        tree[node].sum = (right-left+1) * tree[node].set_val;

        if (left != right) { // not leaf
            tree[node*2].set_val = tree[node].set_val;
            tree[node*2].add_val = 0;
            tree[node*2+1].set_val = tree[node].set_val;
            tree[node*2+1].add_val = 0;
        }
        tree[node].set_val = 0;
    }

    if (tree[node].add_val) {
        tree[node].sum += (right-left+1) * tree[node].add_val;
        if (left != right) {
            tree[node*2].add_val += tree[node].add_val;
            tree[node*2+1].add_val += tree[node].add_val;
        }
        tree[node].add_val = 0;
    }
}


void add(int l, int r, ll val, int node, int left, int right, vector<Node>& tree) {
    push(node, left, right, tree);

    if (r < left || l > right) return;

    if (l <= left && right <= r) {
        tree[node].add_val += val;
        push(node, left, right, tree);
        return;
    }

    int mid = (left+right)/2;
    add(l, r, val, node*2, left, mid, tree);
    add(l, r, val, node*2+1, mid+1, right, tree);
    tree[node].sum = tree[node*2].sum + tree[node*2+1].sum;
}


void set_val(int l, int r, ll val, int node, int left, int right, vector<Node>& tree) {
    push(node, left, right, tree);

    if (r < left || l > right) return;

    if (l <= left && right <= r) {
        tree[node].set_val = val;
        tree[node].add_val = 0;
        push(node, left, right, tree);
        return;
    }

    int mid = (left+right)/2;
    set_val(l, r, val, node*2, left, mid, tree);
    set_val(l, r, val, node*2+1, mid+1, right, tree);
    tree[node].sum = tree[node*2].sum + tree[node*2+1].sum;
}


ll getSum(int l, int r, int node, int left, int right, vector<Node>& tree) {
    push(node, left, right, tree);

    if (r < left || l > right) return 0;

    if (l <= left && right <= r) return tree[node].sum;

    int mid = (left+right)/2;
    return getSum(l, r, node*2, left, mid, tree) +
           getSum(l, r, node*2+1, mid+1, right, tree);
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, q; cin >> n >> q;
    int N = 1;
    while (N < n) N <<= 1;

    vector<Node> tree(N*2);

    rep(i, 0, n-1) {
        int x; cin >> x;
        tree[N+i].sum = x;
    }

    repr(i, N-1, 1) {
        tree[i].sum = tree[i*2].sum + tree[i*2+1].sum;
    }

    while (q--) {
        int type, a, b;
        ll x; cin >> type >> a >> b;
        --a; --b; // 0-based
        if (type != 3) cin >> x;
        if (type == 1) add(a, b, x, 1, 0, N-1, tree);
        else if (type == 2) set_val(a, b, x, 1, 0, N-1, tree);
        else cout << getSum(a, b, 1, 0, N-1, tree) << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
#include <regex>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
constexpr ll MAX = 9e18;
constexpr ll MOD = 1e9 + 7;

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)

const int MAXN = 2e5 + 5;

ll n; vl mountains;
vl Left, Right;

struct SegmentTree {
    ll size; vl tree;

    SegmentTree(ll n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, 0);
    }

    void update(ll idx, ll val) {
        idx += size;
        tree[idx] = max(tree[idx], val);
        while (idx > 1) {
            idx /= 2;
            tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
        }
    }

    ll query(ll left, ll right) {
        ll res = 0;
        left += size, right += size;
        while (left < right) {
            if (left & 1) res = max(res, tree[left++]);
            if (right & 1) res = max(res, tree[--right]);
            left >>= 1; right >>= 1;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    mountains = vl(n);
    REP(i, 0, n-1) cin >> mountains[i];

    Left = vl(n, -1);
    Right = vl(n, n);

    stack<ll> height_stack;
    for (ll i = 0; i < n; ++i) {
        while (!height_stack.empty() && mountains[height_stack.top()] <= mountains[i]) height_stack.pop();
        if (!height_stack.empty()) Left[i] = height_stack.top();
        height_stack.push(i);
    }

    while (!height_stack.empty()) height_stack.pop();
    for (ll i = n - 1; i >= 0; --i) {
        while (!height_stack.empty() && mountains[height_stack.top()] <= mountains[i]) height_stack.pop();
        if (!height_stack.empty()) Right[i] = height_stack.top();
        height_stack.push(i);
    }

    vl dp(n, 1);
    vector<pl> heights;
    REP(i, 0, n-1) heights.emplace_back(mountains[i], i);
    ranges::sort(heights.begin(), heights.end());
    SegmentTree seg(n);

    for (ll i = 0; i < n;) {
        ll j = i;
        while (j < n && heights[j].first == heights[i].first) ++j;

        vl toUpdate;
        REP(k, i, j-1) {
            ll idx = heights[k].second;
            ll left = Left[idx] + 1;
            ll right = Right[idx];

            ll best = 0;
            if (left < idx) best = max(best, seg.query(left, idx));
            if (idx + 1 < right) best = max(best, seg.query(idx + 1, right));

            dp[idx] = best + 1;
            toUpdate.push_back(idx);
        }

        for (ll idx : toUpdate) seg.update(idx, dp[idx]);

        i = j;
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}


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


constexpr int BINMAX = 32;
constexpr int MAXN = 1e5+1;
constexpr int MANQ = 2e5+1;

ll heights[MAXN];
vvi binary_lifting;
int n, q, ql, qr;


struct StackNode {
    int node;
    ll value;
};


int query(int node) {
    int ans = 0;
    repr(k, BINMAX-1, 0) {
        int next = binary_lifting[node][k];
        if (next <= qr) {       
            node = next;
            ans += (1 << k);    
        }
    }
    return ans;
}



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);


    cin >> n >> q;
    stack<StackNode> st;
    binary_lifting.assign(MAXN, vi(BINMAX, INT_MAX));
    rep(i, 1, n) {
        cin >> heights[i];
        while (!st.empty() && st.top().value < heights[i]) {
            binary_lifting[st.top().node][0] = i;
            st.pop();
        }
        st.push({i, heights[i]});
    }


    rep(lift, 1, BINMAX-1) {
        rep(node, 1, n) if (binary_lifting[node][lift-1] < INT_MAX) {
            binary_lifting[node][lift] = binary_lifting[binary_lifting[node][lift-1]][lift-1];
        }
    }


    rep(i, 0, q-1) {
        cin >> ql >> qr;
        cout << query(ql)+1 << "\n";
    }


    
    return 0;
}


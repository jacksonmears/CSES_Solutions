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
    ll total, mxLeft, mxRight, mxSubarray;
};

int n, m, k, segSize = 1;
ll x;
vector<Node> segment;


void update_node(int i) {
    Node *cur = &segment[i];
    Node *left = &segment[i*2];
    Node *right = &segment[i*2 +1];

    cur->total = left->total + right->total;
    cur->mxLeft = max(left->mxLeft, left->total + right->mxLeft);
    cur->mxRight = max(right->mxRight, right->total + left->mxRight);
    cur->mxSubarray = max(max(right->mxSubarray, left->mxSubarray), right->mxLeft + left->mxRight);
}


void initialize_segment_tree() {
    repr(i, segSize-1, 1) {
        update_node(i);
    }
}

void initialize_node(int i, int value) {
    Node *node = &segment[i];
    node->total = value;
    node->mxLeft = value;
    node->mxRight = value;
    node->mxSubarray = value * (value > 0);
}



void update_segment(int k, ll value) {
    int curIndex = k+segSize-1;
    initialize_node(curIndex, value);
    
    for (int i = curIndex/2; i > 0; i /= 2) {
        update_node(i);
    }
}



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    cin >> n >> m;
    while (segSize < n) segSize <<= 1;

    segment.assign(segSize*2, {});
    rep(i, 0, n-1) {
        cin >> x;
        initialize_node(segSize + i, x);
    }

    initialize_segment_tree();

    rep(i, 0, m-1) {
        cin >> k >> x;
        update_segment(k, x);
        cout << segment[1].mxSubarray << "\n";
    }


    
    
    return 0;
}

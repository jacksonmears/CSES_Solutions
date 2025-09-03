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

constexpr int MAXN = 2e5+1;
int n, q, k, a, b, resize = 1;
int pizzeria[MAXN];
vi segment_forward, segment_backward;


void populate_segments() {
    repr(i, resize-1, 1) {
        segment_forward[i] = min(segment_forward[i*2], segment_forward[i*2+1]); 
        segment_backward[i] = min(segment_backward[i*2], segment_backward[i*2+1]);
    }
}

void update(int node, int value) {
    int position = node+resize-1;
    segment_forward[position] = value+node;
    segment_backward[position] = value-node;
    for (int i = position/2; i > 0; i /= 2) {
        segment_forward[i] = min(segment_forward[i*2], segment_forward[i*2+1]); 
        segment_backward[i] = min(segment_backward[i*2], segment_backward[i*2+1]);
    }
}


int query_forwards(int node, int L, int R, int ql) {
    int qr = resize;  
    if (qr < L || R < ql) return INT_MAX;
    if (ql <= L && R <= qr) return segment_forward[node];

    int middle = (L + R)/2;
    int left = query_forwards(2*node, L, middle, ql);
    int right = query_forwards(2*node+1, middle+1, R, ql);
    
    return min(left, right);
}

int query_backwards(int node, int L, int R, int qr) {
    int ql = 1;  
    if (qr < L || R < ql) return INT_MAX;
    if (ql <= L && R <= qr) return segment_backward[node];

    int middle = (L + R)/2;
    int left = query_backwards(2*node, L, middle, qr);
    int right = query_backwards(2*node+1, middle+1, R, qr);

    return min(left, right);
}

int query_both_segments(int pos) {
    return min(
        query_forwards(1, 1, resize, pos) - pos,
        query_backwards(1, 1, resize, pos) + pos
    );
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> q;

    while (resize < n) resize <<= 1;
    segment_forward.assign(resize*2, INT_MAX), segment_backward.assign(resize*2, INT_MAX);

    rep(i, 1, n) {
        cin >> pizzeria[i];
        segment_forward[i+resize-1] = pizzeria[i]+i;
        segment_backward[i+resize-1] = pizzeria[i]-i;
    }

    populate_segments();

    rep(i, 0, q-1) {
        cin >> k >> a;
        if (k == 1) {
            cin >> b;
            update(a, b);
        } else {
            cout << query_both_segments(a) << "\n";
        }
    }

    


    
    return 0;
}


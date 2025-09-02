
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


int n, q;
vi fenwick;


void update(int node, int value) {
    for (int i = node; i <= n; i += i&-i)
        fenwick[i] += value;
}

int query(int q) {
    int i = 0;
    int node = 1 << (31 - __builtin_clz(n)); // clz = count leading zeros (n=16 clz return 27 because in binary 0000000000... 00010000)
    while (node) {
        int next = i + node;
        if (next <= n && fenwick[next] < q) {
            q -= fenwick[next];
            i = next;
        }
        node >>= 1;
    }
    return i + 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    if (!(cin >> n)) return 0;
    fenwick.assign(n+1, 0);

    vi elements(n+1);
    rep(i, 1, n) 
        cin >> elements[i];

    rep(i, 1, n)
        update(i, 1);   

    rep(i, 0, n-1) {
        cin >> q;                        
        int found_node = query(q);                    
        cout << elements[found_node] << " ";
        update(found_node, -1);                      
    }
    return 0;
}


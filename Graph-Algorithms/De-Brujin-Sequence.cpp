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
 
constexpr int MAXN = 1 << 15;
stack<int> path;
stack<int> edges[MAXN];
 
void heirholzer(int node) {

    while (!edges[node].empty()){
        int child = edges[node].top();
        edges[node].pop();
        heirholzer(child);
    }
    
    cout << (node&1);
}
 
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    int n; cin >> n;
 
    if (n == 1) 
        return cout << "01\n", 0;
 
    const int num_nodes = 1 << (n - 1);
 
    rep(node, 0, num_nodes - 1) {
        int v0 = (node << 1) & (num_nodes - 1);
        int v1 = v0 | 1;
        edges[node].push(v0);
        edges[node].push(v1);
    }
 
    heirholzer(0);
 
    rep(i, 0, n-2-1) 
        cout << 0;
 
    return 0;
}
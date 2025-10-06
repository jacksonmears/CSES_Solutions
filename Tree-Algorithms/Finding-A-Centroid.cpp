#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
typedef vector<char> vc;
constexpr int MOD = 1e9 + 7;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = a; i >= b; --i)
 
 
 
constexpr int MAXN = 2e5+1;
int n, centroid = 1;
vi edges[MAXN];
 
 
int dfs(int node, int parent) {
 
    int sum = 1;
    bool valid = true;
    for (int child : edges[node]) if (child != parent && valid) {
        int child_sum = dfs(child, node);
        sum += child_sum;
        valid = (child_sum <= n/2);
    }
 
    if (valid && sum >= (n/2)) centroid = node;
    
    return sum;
}
 
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    cin >> n;
    rep(i, 0, n-2) {
        int a, b; cin >> a >> b;
        edges[a].pb(b);
        edges[b].pb(a);
    }
 
    dfs(1, -1);
    cout << centroid;
 
    return 0;
}
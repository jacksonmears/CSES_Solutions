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


constexpr int MAXN = 2e5+5;
int component[MAXN];
vvi edges;
vvi reverse_edges;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n; cin >> n;
    edges = vvi(n+1); reverse_edges = vvi(n+1);
    component[1] = 1;
    rep(i, 1, n) {
        int x; cin >> x;
        edges[i].pb(x);
        reverse_edges[x].pb(i);
        if (component[x]) component[i] = component[x];
        else if (component[i]) component[x] = component[i];
        else component[x] = i;
    }




    return 0;
}


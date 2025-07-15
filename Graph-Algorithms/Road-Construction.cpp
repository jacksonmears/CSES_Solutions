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



vl parent, componentSize;

ll find(const ll x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool unite(ll a, ll b) {
    a = find(a); b = find(b);
    if (a == b) return false;
    if (componentSize[a] < componentSize[b]) swap(a, b);
    parent[b] = a;
    componentSize[a] += componentSize[b];
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll n, m; cin >> n >> m;
    parent = vl(n+1);
    componentSize = vl(n+1, 1);

    REP(i,1,n) parent[i] = i;

    ll components = n;
    ll maxSize = 1;

    while (m--) {
        ll a, b; cin >> a >> b;
        if (unite(a, b)) {
            components--;
            maxSize = max(maxSize, componentSize[find(a)]);
        }
        cout << components << " " << maxSize << "\n";
    }

    return 0;
}

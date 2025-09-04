
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
int n, q, a, b, values_size;
ll c, d;
ll elements[MAXN];
vl values;
vi fenwick;

struct Query {
    int nodeL, nodeR;
    ll valueL, valueR;
};
vector<Query> queries;


int fetch_compressed_value(int x) {
    return int(lower_bound(values.begin(), values.end(), x) - values.begin());
}

void update(int node, ll value) {
    for (int i = node+1; i <= values_size; i += i&-i) {
        fenwick[i] += value;
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> q;
    queries.assign(n+1, {});
    values.reserve(n+1);
    rep(i, 1, n) {
        cin >> elements[i];
        values.pb(elements[i]);
    }
    
    rep(i, 0, q-1) {
        cin >> a >> b >> c >> d;
        queries.pb({a, b, c, d});
    }
    
    ranges::sort(values);
    values.erase(unique(values.begin(), values.end()), values.end());


    values_size = values.size();
    fenwick.assign(values_size+1, 0);

    rep(i, 1, n) {
        update(fetch_compressed_value(elements[i]), 1);
    }

    cout << endl;
    rep(i, 1, n) cout << elements[i] << " ";
    cout << endl;
    rep(i, 0, fenwick.size()-1) cout << fenwick[i] << " ";
    cout << endl;
    
    
    return 0;
}


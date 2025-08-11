#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<bool> vb;
typedef vector<pl> vp;
constexpr ll MAX = 9e18;
constexpr ll MOD = 1e9 + 7;
const int MAXN = 2e5+1;

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (ll i = a; i <= b; i++)



struct triplet {
    ll smallest, largest, index;
};

ll n;
unordered_map<ll, ll> compression_map;
ll T[MAXN+1];


void update(const ll count, ll a, const ll val){
    while (a <= count) {
        T[a] += val;
        a += a&-a;
    }
}

ll query(ll x){
    ll sum = 0;
    while (x > 0) {
        sum += T[x];
        x -= x&-x;
    }
    return sum;
}

bool compare(const triplet& a, const triplet& b) {
    if (a.smallest == b.smallest)
        return a.largest > b.largest;
    return a.smallest < b.smallest;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    set<ll> set_of_large;

    vector<triplet> elements(n);
    rep(i, 0, n-1) {
        ll a, b; cin >> a >> b;
        elements[i] = {a, b, i};
        set_of_large.insert(b);
    }

    ll count = 0;
    for (auto i: set_of_large) compression_map[i] = ++count;
    ranges::sort(elements, compare);


    update(count, compression_map[elements[n-1].largest], 1);
    vl answer (n, 0);
    for (ll i = n-2; i >= 0; i--) {
        answer[elements[i].index] += query(compression_map[elements[i].largest]);
        update(count, compression_map[elements[i].largest], 1);
    }

    rep(i, 0, n-1) cout << answer[i] << ' '; cout << "\n";

    ranges::fill(answer, 0LL);
    ranges::fill(T, 0LL);
    update(count, 1, 1);
    update(count, compression_map[elements[0].largest] + 1, -1);

    rep(i, 1, n-1) {
        answer[elements[i].index] += query(compression_map[elements[i].largest]);
        update(count, 1, 1);
        update(count, compression_map[elements[i].largest] + 1, -1);
    }

    rep(i, 0, n-1) cout << answer[i] << ' ';
}


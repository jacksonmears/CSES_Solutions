#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<bool> vb;
typedef vector<pl> vp;
typedef vector<vl> vvl;
constexpr ll MAX = 9e18;
constexpr ll MOD = 1e9 + 7;
constexpr int MAXN = 2e5+1;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (ll i = a; i <= b; i++)
#define repr(i, a, b) for (ll i = a; i >= b; i--)


const ll maxN = 2e5+5;
ll n;
ll answer, fenwick[maxN];

struct Data {
    ll value, index;
};
Data elements[maxN];

bool sorting_operation(const Data& a, const Data& b) {
    return a.value == b.value ? b.index < a.index : a.value < b.value;
}

void update(const ll index, const ll value){
    for(ll i = index; i < maxN; i += -i&i)
        fenwick[i] = (fenwick[i] + value) % MOD;
}

ll query(const ll index){
    ll sum = 0;
    for(ll i = index; i > 0; i -= -i&i)
        sum = (sum + fenwick[i]) % MOD;
    return sum;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    rep(i, 0, n-1) {
        ll x; cin >> x;
        elements[i] = {x, i+1};
    }

    sort(elements, elements, sorting_operation);

    rep(i, 0, n-1) {
        const ll index = elements[i].index;
        const ll amount = query(index)+1;
        answer = (answer + amount) % MOD;
        update(index, amount);
    }

    cout << answer;
}

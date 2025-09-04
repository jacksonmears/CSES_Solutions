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


int n;
ll x, y;

struct Customer {
    ll a, b;
};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n; 
    vector<Customer> customers;
    rep(i, 0, n-1) {
        cin >> x >> y;
        Customer arrive = {x, 1};
        Customer leave = {y, -1};
        customers.pb(arrive);
        customers.pb(leave);
    }

    ranges::sort(customers, [](Customer A, Customer B){ 
        if (A.a != B.a) return A.a < B.a;
        return A.b < B.b;
    });


    auto it = customers.begin();
    ll mx = 0, cur = 0;
    while (it != customers.end()) {
        cur += it->b;
        mx = max(mx, cur);
        ++it;
    }

    cout << mx;

    return 0;
}

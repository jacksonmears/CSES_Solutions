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
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll n; cin >> n; set<pl> customers;
    REP(i, 0, n-1) {
        ll a, b; cin >> a >> b;
        customers.insert(MP(a, 1));
        customers.insert(MP(b, -1));
    }

    auto iterator = customers.begin();
    ll maxCustomers = 0, currentCustomers = 0;
    while (iterator != customers.end()) {
        currentCustomers += iterator->second;
        maxCustomers = max(maxCustomers, currentCustomers);
        iterator++;
    }

    cout << maxCustomers;

    return 0;
}

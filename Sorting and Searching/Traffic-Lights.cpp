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


    ll x, n; cin >> x >> n;
    multiset<ll> trafficLights; set<ll> streets;
    streets.insert(0); streets.insert(x); trafficLights.insert(x);

    REP(i, 0, n-1) {
        ll e; cin >> e;
        streets.insert(e);
        auto it = streets.find(e);
        auto up = *next(it);
        auto down = *prev(it);
        trafficLights.erase(trafficLights.find(up-down));
        trafficLights.insert(up-e); trafficLights.insert(e-down);
        cout << *trafficLights.rbegin() << " ";
    }


    return 0;
}

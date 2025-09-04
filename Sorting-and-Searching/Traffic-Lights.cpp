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


int n;
ll x, p;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);


    cin >> x >> n;
    multiset<ll> lights; set<ll> streets;
    streets.insert(0); streets.insert(x); 
    lights.insert(x);

    REP(i, 0, n-1) {
        cin >> p;
        streets.insert(p);
        auto it = streets.find(p);
        auto up = *next(it);
        auto down = *prev(it);
        lights.erase(lights.find(up-down));
        lights.insert(up-p); lights.insert(p-down);
        cout << *lights.rbegin() << " ";
    }


    return 0;
}

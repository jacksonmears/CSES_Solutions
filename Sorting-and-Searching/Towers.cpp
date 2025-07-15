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

    ll n; cin >> n;
    set<pl> cubes;
    ll towerCounter = 0;
    REP(i, 0, n-1) {
        ll e; cin >> e;
        auto it = cubes.lower_bound(MP(e+1, 0));

        if (it == cubes.end() || it->first == e) {
            towerCounter++;
        } else cubes.erase(it);
        if (e != 1) {cubes.insert(MP(e, i));}
    }

    cout << towerCounter << endl;




    return 0;
}

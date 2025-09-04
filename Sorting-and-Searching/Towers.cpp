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
ll k;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    multiset<ll> cubes;
    REP(i, 0, n-1) {
        cin >> k;
        auto it = cubes.lower_bound(k+1);

        if (it != cubes.end()) 
            cubes.erase(it);
        
        cubes.insert(k);
        
    }

    cout << cubes.size() << endl;

    return 0;
}

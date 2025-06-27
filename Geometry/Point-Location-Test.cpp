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



// cross product of A->B and A->C
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll n; cin >> n;
    while (n--) {
        ll x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        ll val = (x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1);

        if (val == 0) cout << "TOUCH\n";
        else if (val > 0) cout << "LEFT\n";
        else cout << "RIGHT\n";
    }

    return 0;
}

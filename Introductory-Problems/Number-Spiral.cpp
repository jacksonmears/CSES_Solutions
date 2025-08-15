#include <bits/stdc++.h>
#include <regex>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
constexpr ll MAX = 9e18;
constexpr ll MOD = 1e9 + 7;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)


void solve(const ll& row, const ll& column) {

    if (column >= row) {
        if (column&1)
            cout << column * column - row + 1 << '\n';
        else
            cout << (column - 1) * (column - 1) + 1 + row - 1 << '\n';
    } else {
        if (!(row&1))
            cout << row * row - column + 1 << '\n';
        else
            cout << (row - 1) * (row - 1) + 1 + column - 1 << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);


    ll t; cin >> t;
    while (t--) {
        ll y, x; cin >> y >> x;
        solve(y, x);
    }


    return 0;
}
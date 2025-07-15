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


string solve() {
    ll a, b; cin >> a >> b;

    ll mx = max(a, b), mn = min(a, b);
    if (mx > mn*2) return "NO";


    ll d = mx - mn;
    mx -= d*2, mn -= d;
    return (!(mx%3) && !(mn%3) || mx%3==2 && mn%3 == 1) ? "YES" : "NO";
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll t; cin >> t;
    while (t--) {

        cout << solve() << '\n';

    }


    return 0;
}
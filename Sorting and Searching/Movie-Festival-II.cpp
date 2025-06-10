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

    ll n, k; cin >> n >> k;
    vector<pl> movies(n);

    REP(i, 0, n-1) {
        ll a, b; cin >> a >> b;
        movies[i] = {b, a};
    }
    ranges::sort(movies);
    multiset<ll> movieEndingTimes;
    REP(i, 0, k-1) movieEndingTimes.insert(0);

    ll watched = 0;
    for (auto [end, start] : movies) {
        auto movieIterator = movieEndingTimes.upper_bound(start);
        if (movieIterator == movieEndingTimes.begin()) continue;
        movieIterator--;
        movieEndingTimes.erase(movieIterator); movieEndingTimes.insert(end);
        watched++;
    }

    cout << watched << '\n';


    return 0;
}

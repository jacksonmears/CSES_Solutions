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

    ll n; cin >> n; set<pl> movies;
    REP(i, 0, n-1) {
        ll a, b; cin >> a >> b;
        movies.insert(MP(b, a));
    }

    auto iterator = movies.begin();
    ll endOfPreviousMovie = 0, movieCounter = 0;
    while (iterator != movies.end()) {
        if (iterator->second >= endOfPreviousMovie) {
            movieCounter++;
            endOfPreviousMovie = iterator->first;
        }
        iterator++;
    }

    cout << movieCounter;

    return 0;
}

#include <bits/stdc++.h>
#include <regex>
using namespace std;
typedef long long ll;
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
    list<ll> remainingValues; //linked list
    REP(i, 1, n) remainingValues.push_back(i);
    auto iterator = remainingValues.begin();
    while (!remainingValues.empty()) {
        iterator++;
        if (iterator == remainingValues.end()) iterator = remainingValues.begin();
        cout << *iterator << ' ';
        iterator = remainingValues.erase(iterator);
        if (iterator == remainingValues.end()) iterator = remainingValues.begin();
    }

    return 0;
}

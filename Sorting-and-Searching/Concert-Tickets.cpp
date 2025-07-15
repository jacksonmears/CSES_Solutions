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

    ll n, m; cin >> n >> m;
    multiset<ll> priceOfTickets;
    REP(i, 0, n-1) {
        ll newPrice; cin >> newPrice;
        priceOfTickets.insert(newPrice);
    }

    REP(i, 0, m-1) {
        ll desiredPrice; cin >> desiredPrice;
        auto iterator = priceOfTickets.lower_bound(desiredPrice+1);
        if (iterator == priceOfTickets.begin()) cout << "-1" << "\n";

        else{
            iterator--;
            cout << *iterator << "\n";
            priceOfTickets.erase(iterator);
        }
    }


    return 0;
}

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

int n, m;
ll h, t;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    multiset<ll> ticket_prices;
    REP(i, 0, n-1) {
        cin >> h;
        ticket_prices.insert(h);
    }

    REP(i, 0, m-1) {
        cin >> t;
        auto it = ticket_prices.lower_bound(t+1);
        if (it == ticket_prices.begin()) cout << "-1" << "\n";

        else{
            it--;
            cout << *it << "\n";
            ticket_prices.erase(it);
        }
    }


    return 0;
}

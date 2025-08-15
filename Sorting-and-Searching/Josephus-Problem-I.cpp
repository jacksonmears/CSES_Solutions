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
    list<ll> people; //linked list
    REP(i, 1, n) people.push_back(i);

    auto it = people.begin();
    while (!people.empty()) {
        it++;
        if (it == people.end())
            it = people.begin();

        cout << *it << ' ';

        it = people.erase(it);
        if (it == people.end())
            it = people.begin();
    }


    return 0;
}

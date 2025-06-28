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


void rebalance_sets(multiset<ll>& low, multiset<ll>& high, ll n, ll& sum_low, ll& sum_high) {
    while (low.size() > (n + 1) / 2) {
        auto it = prev(low.end());
        sum_low -= *it;
        sum_high += *it;
        high.insert(*it);
        low.erase(it);
    }
    while (low.size() < (n + 1) / 2) {
        auto it = high.begin();
        sum_high -= *it;
        sum_low += *it;
        low.insert(*it);
        high.erase(it);
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll k, n; cin >> k >> n;

    vector<ll> elements(k);
    REP(i, 0, k-1) cin >> elements[i];

    multiset<ll> low, high;
    ll sum_of_bottom_half = 0, sum_of_top_half = 0;


    REP(i, 0, n-1) {
        low.insert(elements[i]);
        sum_of_bottom_half += elements[i];
    }
    rebalance_sets(low, high, n, sum_of_bottom_half, sum_of_top_half);

    auto median = *prev(low.end());
    cout << median * (ll)low.size() - sum_of_bottom_half + sum_of_top_half - median * (ll)high.size();

    REP(i, n, k-1) {
        if (low.find(elements[i - n]) != low.end()) {
            low.erase(low.find(elements[i - n]));
            sum_of_bottom_half -= elements[i - n];
        } else {
            high.erase(high.find(elements[i - n]));
            sum_of_top_half -= elements[i - n];
        }

        if (!low.empty() && elements[i] <= *prev(low.end())) {
            low.insert(elements[i]);
            sum_of_bottom_half += elements[i];
        } else {
            high.insert(elements[i]);
            sum_of_top_half += elements[i];
        }

        rebalance_sets(low, high, n, sum_of_bottom_half, sum_of_top_half);

        median = *prev(low.end());
        ll cost = median * (ll)low.size() - sum_of_bottom_half + sum_of_top_half - median * (ll)high.size();
        cout << " " << cost;
    }

    cout << '\n';
    return 0;
}


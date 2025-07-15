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

    ll n, a, b; cin >> n >> a >> b;
    vl prefix(n + 1, 0);
    REP(i, 0, n-1) {
        ll newNumber; cin >> newNumber;
        prefix[i + 1] = prefix[i] + newNumber;
    }

    deque<pl> dq;
    ll maxSum = LLONG_MIN;

    REP(i, a, n) {
        ll newVal = prefix[i - a];
        while (!dq.empty() && dq.back().second >= newVal) dq.pop_back();
        dq.emplace_back(i - a, newVal);

        while (!dq.empty() && dq.front().first < i - b) dq.pop_front();

        maxSum = max(maxSum, prefix[i] - dq.front().second);
    }

    cout << maxSum << '\n';

    return 0;
}

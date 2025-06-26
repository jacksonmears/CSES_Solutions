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


int MX = 1000005;
vl preCalculate(MX, 0);

void populateAnswer() {
    REP(i, 1, MX) {
        for (ll j = i; j < MX; j += i) preCalculate[j]++;
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    populateAnswer();
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        cout << preCalculate[n] << "\n";
    }

    return 0;
}

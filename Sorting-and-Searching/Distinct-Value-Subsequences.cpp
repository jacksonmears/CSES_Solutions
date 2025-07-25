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
    unordered_map<ll, ll> distinctValueFrequency;
    REP(i, 0, n-1) {
        ll x; cin >> x;
        distinctValueFrequency[x]++;
    }

    ll result = 1;
    for (auto &[key, frequency] : distinctValueFrequency) {
        result = result * (frequency + 1) % MOD;
    }

    cout << (result-1+MOD) % MOD; //remove empty subsequence

    return 0;
}

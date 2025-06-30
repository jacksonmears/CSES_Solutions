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


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n; cin >> n;

    vector<ll> elements(n);
    REP(i, 0, n-1) cin >> elements[i];

    // XOR basis with at most 60 elements (since x_i ≤ 1e9)
    vector<ll> basis(60, 0);

    for (ll value : elements) {
        for (int bit = 59; bit >= 0; bit--) {
            if ((value >> bit) & 1) {
                if (!basis[bit]) {
                    basis[bit] = value;
                    break;
                }
                value ^= basis[bit];
            }
        }
    }

    ll result = 0;
    for (int bit = 59; bit >= 0; bit--) {
        if ((result ^ basis[bit]) > result)
            result ^= basis[bit];
    }

    cout << result << "\n";
    return 0;
}



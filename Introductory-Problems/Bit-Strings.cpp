#include <bits/stdc++.h>
#include <regex>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
constexpr ll MAX = 9e18;
constexpr ll MOD = 1e9 + 7;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)


ll binary_exponentiation(int& n) {
    ll result = 1;
    ll bin = 2;
    while (n) {
        if (n&1) result = result * bin % MOD;
        bin = bin * bin % MOD;
        n >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;

    cout << binary_exponentiation(n);


    return 0;
}
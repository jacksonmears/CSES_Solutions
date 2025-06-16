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
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)




int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll k, n, x, a, b, c; cin >> k >> n >> x >> a >> b >> c;
    vl prefix(k+1); prefix[0] = 0, prefix[1] = x;
    REP(i, 2, k) {
        prefix[i] = (a*(prefix[i-1]-prefix[i-2]) + b) % c + prefix[i-1];
    }
    ll right = n; ll xorAnswer = 0;
    while (right <= k) {
        xorAnswer ^= prefix[right]-prefix[right-n];
        right++;
    }

    cout << xorAnswer;

    return 0;
}
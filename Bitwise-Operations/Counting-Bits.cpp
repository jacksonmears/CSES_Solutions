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
    ll total_bits = 0;
    for (ll i = 0; (1LL << i) <= n; i++) {
        ll block_size = 1LL << (i + 1);
        ll ones_per_block = block_size >> 1ll;
        ll total_full_blocks = (n + 1) / block_size;
        ll contribution = total_full_blocks * ones_per_block;

        ll remainder = (n + 1) % block_size;
        ll leftover = max(0LL, remainder - ones_per_block);

        total_bits += contribution + leftover;
    }

    cout << total_bits << "\n";
    return 0;
}



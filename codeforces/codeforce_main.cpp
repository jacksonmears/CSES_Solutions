#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef vector<char> vc;
constexpr int MOD = 1e9 + 7;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = a; i >= b; --i)
 


void solve() {
    int n, k; cin >> n >> k;

    int total_pairs = n * (n - 1) / 2;
    int need = total_pairs - k;  

    vi blocks;
    blocks.reserve(total_pairs+1);
    int remaining = n;

    while (remaining > 0) {
        int L = 1;
        while (L + 1 <= remaining && (L + 1) * L / 2 <= need) ++L;
        blocks.push_back(L);
        need -= L * (L - 1) / 2;
        remaining -= L;
    }

    if (need != 0) {  
        cout << 0 << '\n';
        return;
    }

    vi perm;
    int cur = n;
    for (int L : blocks) {
        vi segment; segment.reserve(blocks.size());
        for (int i = cur - L + 1; i <= cur; ++i) segment.push_back(i);
        perm.insert(perm.end(), segment.begin(), segment.end());
        cur -= L;
    }

    for (int x : perm) cout << x << ' ';
    cout << '\n';
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        solve();
    }
}
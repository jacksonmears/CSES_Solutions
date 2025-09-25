#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
constexpr int MOD = 1e9 + 7;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = a; i >= b; --i)


ll n, ans = 0, d = 1;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    while (d <= n) {
        ll q = n / d;
        ll last = n / q; // largest d' with floor(n/d') == q

        // sum of integers from d to last = (d + last) * (last - d + 1) / 2
        __int128 cnt = (last - d + 1);
        __int128 s = (d + last) * cnt / 2; // exact in 128-bit

        ll s_mod = (s % MOD);
        ll q_mod = (q % MOD);

        ans = (ans + (q_mod * s_mod ) % MOD) % MOD;

        d = last + 1;
    }

    cout << (ans % MOD + MOD) % MOD << '\n';
    return 0;
}

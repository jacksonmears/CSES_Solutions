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
 

 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
 
    int n, x; cin >> n >> x;
    vi prices(n); 
    rep(i, 0, n-1) 
        cin >> prices[i];

    vpi books;
    rep(i, 0, n-1) {
        int h; cin >> h;
        books.emplace_back(prices[i], h);
    }
 
    vi dp(x+1, -1); 
    dp[0] = 0; 
    int mx = 0;

    for (auto book : books) {
        for (ll i = x-book.first; i >= 0; i--) {
            if (dp[i] >= 0) {
                dp[i+book.first] = max(dp[i+book.first], dp[i]+book.second);
                mx = max(mx, dp[i+book.first]);
            }
        }
    }

 
    cout << mx;
 
    return 0;

}
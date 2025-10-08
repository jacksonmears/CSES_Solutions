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
    int n, m; cin >> n >> m;
    string str; cin >> str;
    unordered_map<int, int> black;
    rep(i, 0, n-1) {
        int a; cin >> a;
        black[a+1] ? black[a] = black[a+1] : black[a] = a+1;
    }

    rep(i, 1, n) {
        int index = 1;
        rep(c, 0, i-1) {
            if (str[c] == 'A') ++index;
            else {
                if (black.find(index+1) == black.end()) ++index;
                else {
                    index = *upper_bound(black.begin(), black.end(), index);
                }
            }
        }
    }

}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}
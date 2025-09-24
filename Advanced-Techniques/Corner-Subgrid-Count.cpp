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

constexpr int MAXN = 3000;
int n, k;
bitset<26> handled;
string grid[MAXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    cin >> n >> k;
    rep(i, 0, n-1) cin >> grid[i];


    vector<vb> sets(26, vb((n*(n-1))/2, false));
    rep(row, 0, n-1) {
        vvi seen(26); 
        rep(i, 0, 25) seen[i].reserve(n);

        rep(col, 0, n-1) {
            int c = grid[row][col]-'A';
            if (handled[c]) continue;
            for (int p : seen[c]) {
                int calc = p*n - (p*(p+1))/2 + (col-p-1);
                if (sets[c][calc]) {
                    handled.set(c);
                    break;
                }
                sets[c][calc] = true;
            }

            seen[c].pb(col);
        }
    }

    rep(i, 0, k-1) cout << (handled[i] ? "YES" : "NO") << "\n"; 


    
    return 0;
}

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


constexpr int MAXN = 500;
int n, m;
char c;
char grid[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    
    rep(row, 0, n-1) {
        rep(column, 0, m-1) {
            cin >> c; 
            c = 'A'+(c-'A'+1)%4;
            int count = 1;
            while (column > 0 && c == grid[row][column-1] || row > 0 && grid[row-1][column] == c && count < 5) {
                ++count;
                c = 'A'+(c-'A'+count)%4;
            }
            if (count >= 5) return cout << "IMPOSSIBLE", 0;

            cout << c;
            grid[row][column] = c;
        } cout << endl;
    }



    return 0;
}

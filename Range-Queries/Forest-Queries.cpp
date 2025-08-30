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
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define repr(i, a, b) for (int i = a; i >= b; i--)



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vvi forest(n+1, vi(n+1, 0));

    rep(row, 1, n) {
        string s; cin >> s;
        rep(column, 1, n) {
            forest[row][column] = forest[row-1][column] + forest[row][column-1] - forest[row-1][column-1] + (s[column-1] == '*');
        }
    }


    rep(i, 0, q-1) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

        cout << forest[x2][y2] - forest[x1-1][y2] - forest[x2][y1-1] + forest[x1-1][y1-1] << "\n";
    }


    return 0;
}


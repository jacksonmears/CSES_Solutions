#include <bits/stdc++.h>
#include <regex>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
const int maxOfN = 1e5+1;
constexpr ll MOD = 1e9 + 7;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)




int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll n, m; cin >> n >> m;
    vector<vector<char>> grid (n, vector<char>(m));
    REP(row, 0, n-1) {
        REP(column, 0, m-1) {
            char c; cin >> c;
            ll changeIterator = 1; char newChar = 'A'+(c-'A'+1)%4;
            while (column > 0 && newChar == grid[row][column-1] || row > 0 && grid[row-1][column] == newChar && changeIterator < 5) {
                changeIterator++;
                newChar = 'A'+(c-'A'+changeIterator)%4;
            }
            if (changeIterator >= 5) return cout << "IMPOSSIBLE", 0;
            cout << newChar;
            grid[row][column] = newChar;
        } cout << endl;
    }



    return 0;
}

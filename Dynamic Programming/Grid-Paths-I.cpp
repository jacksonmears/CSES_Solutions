#include <bits/stdc++.h>
#include <regex>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
constexpr ll MAX = 9e18;
constexpr ll MOD = 1e9 + 7;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)





int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll n; cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    vector<vl> dynamicProgramming(n, vl(n, 0)); dynamicProgramming[0][0] = 1;

    REP(i, 0, n-1) {
        REP(j, 0, n-1) cin >> grid[i][j];
    }

    for (int row = 0; row < n; row++) {
        for (int column = 0; column < n; column++) {
            if (grid[row][column] == '*') {
                dynamicProgramming[row][column] = 0;
                continue;
            }
            if (row > 0) dynamicProgramming[row][column] = (dynamicProgramming[row][column] + dynamicProgramming[row - 1][column]) % MOD;
            if (column > 0) dynamicProgramming[row][column] = (dynamicProgramming[row][column] + dynamicProgramming[row][column - 1]) % MOD;
        }
    }

    cout << dynamicProgramming[n - 1][n - 1] << "\n";



    return 0;
}
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
 
int n;
constexpr int MAXN = 1000;
 
int grid[MAXN][MAXN];
bool seen[MAXN][MAXN];
 
int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};
 
bool inBounds(int row, int column) {
    return row >= 0 && column >= 0 && row < n && column < n;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
    cin >> n;
    queue<pi> bfs;
 
    bfs.push({0, 0});
    grid[0][0] = 0;
    seen[0][0] = true;
 
    while (!bfs.empty()) {
        auto [row, column] = bfs.front();
        bfs.pop();
 
        //check each possible move a knight can make (8 total moves)
        rep(i, 0, 7) {
            int moveRow = row + dr[i], moveColumn = column + dc[i];
            if (inBounds(moveRow, moveColumn) && !seen[moveRow][moveColumn]) {
                seen[moveRow][moveColumn] = true;
                grid[moveRow][moveColumn] = grid[row][column] + 1;
                bfs.push({moveRow, moveColumn});
            }
        }
    }
 
    rep(row, 0, n-1) {
        rep(column, 0, n-1)
            cout << grid[row][column] << " ";
 
        cout << "\n";
    }
 
 
    return 0;
}
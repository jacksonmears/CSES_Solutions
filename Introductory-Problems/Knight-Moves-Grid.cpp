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


ll n; ll MAX_N = 1000;
vector<vector<ll>> grid(MAX_N, vector<ll>(MAX_N, -1));
vector<vector<bool>> visited(MAX_N, vector<bool>(MAX_N, false));

int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool inBounds(ll row, ll column) {
    return row >= 0 && column >= 0 && row < n && column < n;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    queue<pl> bfs;

    bfs.push({0, 0});
    grid[0][0] = 0;
    visited[0][0] = true;

    while (!bfs.empty()) {
        auto [row, column] = bfs.front();
        bfs.pop();

        //check each possible move a knight can make (8 total moves)
        REP(i, 0, 7) {
            ll moveRow = row + dr[i], moveColumn = column + dc[i];
            if (inBounds(moveRow, moveColumn) && !visited[moveRow][moveColumn]) {
                visited[moveRow][moveColumn] = true;
                grid[moveRow][moveColumn] = grid[row][column] + 1;
                bfs.push({moveRow, moveColumn});
            }
        }
    }

    REP(row, 0, n-1) {
        REP(column, 0, n-1) cout << grid[row][column] << " ";
        cout << "\n";
    }


    return 0;
}

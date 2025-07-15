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


const int gridLength = 7;
string path;
bool visited[gridLength][gridLength];
ll result = 0;

ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
char direction[4] = {'D', 'U', 'R', 'L'};

bool inside(const ll row, const ll column) {
    return row >= 0 && row < gridLength && column >= 0 && column < gridLength;
}

void dfs(const  ll row, const ll column, const ll moveCounter) {
    if (row == 6 && column == 0) {
        if (moveCounter == 48) result++;
        return;
    }

    if ((row == 0 || visited[row - 1][column]) && (row == gridLength - 1 || visited[row + 1][column]) &&
        (column > 0 && !visited[row][column - 1]) && (column < gridLength - 1 && !visited[row][column + 1]))
        return;
    if ((column == 0 || visited[row][column - 1]) && (column == gridLength - 1 || visited[row][column + 1]) &&
        (row > 0 && !visited[row - 1][column]) && (row < gridLength - 1 && !visited[row + 1][column]))
        return;

    visited[row][column] = true;

    if (path[moveCounter] != '?') {
        ll directionIndex;
        for (directionIndex = 0; directionIndex < 4; directionIndex++) {
            if (path[moveCounter] == direction[directionIndex]) break;
        }
        int newRow = row + dx[directionIndex], newColumn = column + dy[directionIndex];
        if (inside(newRow, newColumn) && !visited[newRow][newColumn]) {
            dfs(newRow, newColumn, moveCounter + 1);
        }
    } else {
        for (int directionIndex = 0; directionIndex < 4; directionIndex++) {
            int newRow = row + dx[directionIndex], newColumn = column + dy[directionIndex];
            if (inside(newRow, newColumn) && !visited[newRow][newColumn]) {
                dfs(newRow, newColumn, moveCounter + 1);
            }
        }
    }

    visited[row][column] = false;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> path;
    dfs(0, 0, 0);
    cout << result;


    return 0;
}

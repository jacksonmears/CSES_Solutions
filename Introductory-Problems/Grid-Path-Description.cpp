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


constexpr int MAXN = 7;
string path;
bool seen[MAXN][MAXN];
int result = 0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char direction[4] = {'D', 'U', 'R', 'L'};

bool check_boundaries(const ll row, const ll column) {
    return row >= 0 && row < MAXN && column >= 0 && column < MAXN;
}

void dfs(const  ll row, const ll column, const ll move_count) {
    if (row == 6 && column == 0) {
        if (move_count == 48) result++;
        return;
    }

    if ((row == 0 || 
        seen[row - 1][column]) && (row == MAXN - 1 || seen[row + 1][column]) && (column > 0 && !seen[row][column - 1]) && (column < MAXN - 1 && !seen[row][column + 1]))
        return;
    if ((column == 0 || 
        seen[row][column - 1]) && (column == MAXN- 1 || seen[row][column + 1]) && (row > 0 && !seen[row - 1][column]) && (row < MAXN - 1 && !seen[row + 1][column]))
        return;

    seen[row][column] = true;

    if (path[move_count] != '?') {
        int i;
        for (i = 0; i < 4; ++i) 
            if (path[move_count] == direction[i]) break;
        
        int newRow = row + dx[i], newColumn = column + dy[i];
        if (check_boundaries(newRow, newColumn) && !seen[newRow][newColumn]) 
            dfs(newRow, newColumn, move_count + 1);
        
    } else {
        rep(i, 0, 3) {
            int newRow = row + dx[i], newColumn = column + dy[i];
            if (check_boundaries(newRow, newColumn) && !seen[newRow][newColumn]) 
                dfs(newRow, newColumn, move_count + 1);
            
        }
    }

    seen[row][column] = false;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> path;
    dfs(0, 0, 0);
    cout << result;


    return 0;
}

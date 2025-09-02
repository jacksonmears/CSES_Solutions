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


constexpr int N = 8;

int solutions = 0;
int check_row[N], check_column[N], check_diag_left[N*2], check_diag_right[N*2];
int grid[N][N];


bool check_valid_square(int row, int column) {
    return grid[row][column] == 1 || check_row[row] == 1 || check_column[column] == 1 || check_diag_left[row+column] == 1 || check_diag_right[N-1+row-column] == 1;
}


void update_checks(int row, int column) {
    check_row[row] = 1; check_column[column] = 1;
    check_diag_left[row+column] = 1; check_diag_right[N-1+row-column] = 1;
}


void backtrack(int row, int column) {
    check_row[row] = 0; check_column[column] = 0;
    check_diag_left[row+column] = 0; check_diag_right[N-1+row-column] = 0;
}


void dfs(const int row, const int column, const int queen_count){
    if (column > N-1 || row > N-1 || queen_count < column) return;


    if (check_valid_square(row, column))
        dfs(row + 1, column, queen_count);

    else{
        update_checks(row, column);
        if (queen_count == N-1) ++solutions;
        
        dfs(0, column + 1, queen_count + 1);
        backtrack(row, column);
        dfs(row + 1, column, queen_count);

    }
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    char ch;

    rep(row, 0, N-1) {
        rep(column, 0, N-1) {
            cin >> ch;
            if (ch == '*'){
                grid[row][column] = 1;
            }
        }
    }

    dfs(0, 0, 0);

    cout << solutions;


    return 0;
}
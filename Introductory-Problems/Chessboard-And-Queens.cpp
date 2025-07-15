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


ll countOfSolutions = 0;

void dfs(const ll row, const ll col, vl& rowCheck, vl& colCheck, vl& diagLeftCheck, vl& diagRightCheck, vector<vl> grid, const ll numQueens){
    if (col > 7 || row > 7 || numQueens < col) return;


    if (grid[row][col] == 1 || rowCheck[row] == 1 || colCheck[col] == 1 || diagLeftCheck[row+col] == 1 || diagRightCheck[7+row-col] == 1){
        dfs(row + 1, col, rowCheck, colCheck, diagLeftCheck, diagRightCheck, grid, numQueens);
    }

    else{
        rowCheck[row] = 1;
        colCheck[col] = 1;
        diagLeftCheck[row+col] = 1;
        diagRightCheck[7+row-col] = 1;
        if (numQueens == 7){
            countOfSolutions++;
        }
        dfs(0, col + 1, rowCheck, colCheck, diagLeftCheck, diagRightCheck, grid, numQueens + 1);
        rowCheck[row] = 0;
        colCheck[col] = 0;
        diagLeftCheck[row+col] = 0;
        diagRightCheck[7+row-col] = 0;
        dfs(row + 1, col, rowCheck, colCheck, diagLeftCheck, diagRightCheck, grid, numQueens);

    }
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    vl rowCheck(8,0), colCheck(8,0);
    vl diagLeftCheck(15,0), diagRightCheck(15,0);
    vector<vl> grid(8, vl(8));
    for (ll row = 0; row < 8; row++){
        for (ll col = 0; col < 8; col++){
            char ch; cin >> ch;
            if (ch == '*'){
                grid[row][col] = 1;
            }
        }
    }

    ll row = 0; ll col = 0;
    dfs(row, col, rowCheck, colCheck, diagLeftCheck, diagRightCheck, grid, 0);
    cout << countOfSolutions;


    return 0;
}
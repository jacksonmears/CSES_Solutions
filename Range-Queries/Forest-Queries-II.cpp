#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#if __has_include("../include/print_ostream.h")
    #include "../include/print_ostream.h"
#endif
using namespace std;

using ll = long long;
using d = double;
using ld = long double;

using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vvb = vector<vb>;
using vl = vector<ll>;
using vd = vector<d>;
using vld = vector<ld>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using pldld = pair<ld, ld>;
using vpii = vector<pii>;
using vvl = vector<vl>;
using vpl = vector<pll>;
using vc = vector<char>;

#define pb push_back
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define repr(i,a,b) for (int i = a; i >= b; --i)

constexpr uint32_t MOD = 1e9 + 7;
constexpr ll infl = 1e10;



void update(vvi& grid, int row, int col, int n, int value) {
    for (int i = row; i <= n; i += i&-i) {
        for (int j = col; j <= n; j += j&-j) {
            grid[i][j] += value;
        }
    }
}

int query(vvi& grid, int row, int col) {
    int sum = 0;

    for (int i = row; i > 0; i -= i&-i) {
        for (int j = col; j > 0; j -= j&-j) {
            sum += grid[i][j];
        }
    }

    return sum;
}



void handle1(vvi& grid, vvb& state, int n) {
    int row, col; cin >> row >> col;
    
    bool isTree = state[row][col];
    int value = (isTree*-1 + !isTree*1);
    update(grid, row, col, n, value);

    state[row][col] = !state[row][col];
}


void handle2(vvi& grid, int n) {
    int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
    int sum = 0;

    sum += query(grid, y2, x2);
    sum -= query(grid, y1-1, x2);
    sum -= query(grid, y2, x1-1);
    sum += query(grid, y1-1, x1-1);

    cout << sum << "\n";

}




int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vvi grid(n+1, vi(n+1, 0));

    rep(row, 1, n) {
        string s; cin >> s;
        rep(col, 1, n) if (s[col-1] == '*') {
            state
            state[row][col] = 1;
            update(grid, row, col, n, 1);
        }
    }



    rep(i,1,q) {
        int x; cin >> x;
        (x==1) ? handle1(grid, state, n) : handle2(grid, n);
    }


   return 0;
}


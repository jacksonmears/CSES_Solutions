#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#if __has_include("../include/print_ostream.h")
    #include "../include/print_ostream.h"
#endif
using namespace std;

using ll = int64_t;

using vi = vector<int32_t>;
using vvi = vector<vi>;
using pi = pair<int32_t, int32_t>;
using vpi = vector<pi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using vb = vector<bool>;
using vc = vector<char>;

#define pb push_back
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define repr(i,a,b) for (int i = a; i >= b; --i)

constexpr uint32_t MOD = 1e9 + 7;






template<size_t N>
struct Vectors {
    unsigned long long seen[((N*N)/64)+1]{};
    int data[N+1][N+1]{};

    constexpr bool get(size_t i) const { return (seen[i >> 6] >> (i & 63)) & 1ULL; }

    constexpr void set(size_t i) {seen[i>>6] |= (1ULL << (i&63));}
};


template<size_t N>
constexpr Vectors<N+1> foo() {
    Vectors<N+1> v;
    v.seen[0] = 1ULL;

    constexpr auto inBounds = [](int x, int y, int n) { return x >= 0 && y >= 0 && x < n && y < n; };

    constexpr int8_t dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    constexpr int8_t dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    size_t head = 0, tail = 0;
    size_t sizeBFS = N*N;

    pi bfs[sizeBFS];
    bfs[tail++] = {0,0};

    while (head < sizeBFS) {
        auto [row, col] = bfs[head++];

        rep(i, 0, 7) {
            size_t moveRow = row + dr[i];
            size_t moveColumn = col + dc[i];
            unsigned long long hash = moveRow*N + moveColumn;

            if (inBounds(moveRow, moveColumn, N) && !v.get(hash)) {
                v.data[moveRow][moveColumn] = v.data[row][col]+1;
                v.set(hash);
                bfs[tail++] = {moveRow, moveColumn};
            }
        }
    }

    return v;
}

constexpr Vectors v = foo<10'000>();



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    
    int n; cin >> n;

    rep(i, 0, n-1) {
        rep(j, 0, n-1) {
            cout << v.data[i][j] << ' ';
        } cout << '\n';
    }



    return 0;
}

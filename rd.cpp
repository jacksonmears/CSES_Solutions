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
struct Vector {
    int data[N]{};
};


template<size_t N>
constexpr Vector<N+1> dp() {
    Vector<N+1> p;

    rep(i, 1, N) {
        int t = i;
        int mn = INT_MAX;
        while (t) {
            int d = t%10;
            if (d) mn = min(mn, p.data[i-d]);
            t /= 10;
        }
        p.data[i] = mn+1;
    }

    return p;
}


constexpr Vector d = dp<1'000'000>();



int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;

    cout << d.data[n];
    

    return 0;
}
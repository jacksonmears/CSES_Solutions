// #pragma GCC optimize("O3,unroll-loops")
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


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, a, b; cin >> n >> m;

    vi inDegrees(n+1);
    vi ans(n+1);
    vvi grid(n+1);

    rep(i, 0, m-1) 
    {
        cin >> a >> b;
        grid[b].push_back(a);
        ++inDegrees[a];
    }

    priority_queue<int> kahn;
    rep(i, 1, n)
        if(!inDegrees[i]) 
            kahn.push(i);
 
    int i = n;
    while(!kahn.empty())
    {
        int node = kahn.top(); kahn.pop();
        ans[i--] = node;

        for(int parent : grid[node])
            if(!--inDegrees[parent])
                kahn.push(parent);
    }
 
    rep(j, 1, n)
        cout << ans[j] << " ";


    return 0;
}
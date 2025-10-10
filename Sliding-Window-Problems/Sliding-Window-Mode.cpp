#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
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
 
 
 
void removeOld(vi& elements, map<int, int>& cnt, vector<set<int>>& sets, int i) {
    sets[cnt[elements[i]]].erase(elements[i]);
    --cnt[elements[i]];
    sets[cnt[elements[i]]].insert(elements[i]);
}
 
 
void addNew(vi& elements, map<int, int>& cnt, vector<set<int>>& sets, int i) {
    sets[cnt[elements[i]]].erase(elements[i]);
    ++cnt[elements[i]];
    sets[cnt[elements[i]]].insert(elements[i]);
}
 
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    int n, k; cin >> n >> k;
    vi elements(n);
    rep(i, 0, n-1) cin >> elements[i];
 
    int mx = 0; 
    map<int, int> cnt;
    vector<set<int>> sets(k+1);
 
    rep(i, 0, k-1) {
        sets[cnt[elements[i]]].erase(elements[i]);
        mx = max(mx, ++cnt[elements[i]]);
        sets[cnt[elements[i]]].insert(elements[i]);
    } cout << *sets[mx].begin() << " ";
 
    rep(i, k, n-1) {
        removeOld(elements, cnt, sets, i-k);
        if (sets[mx].size() == 0) --mx;
        addNew(elements, cnt, sets, i);
        mx = max(mx, cnt[elements[i]]);
        cout << *sets[mx].begin() << " ";
    }
 
    
    return 0;
}
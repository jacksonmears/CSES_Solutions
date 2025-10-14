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
 
 
inline void removeOld(vi& elements, map<int, int>& cnt, set<int>& notSeen, int i) {
    if (--cnt[elements[i]] == 0) notSeen.insert(elements[i]);
}
 
 
inline void addNew(vi& elements, map<int, int>& cnt, set<int>& notSeen, int i, int k) {
    if (++cnt[elements[i]] == 1 && elements[i] < k)
        notSeen.erase(elements[i]);
}

 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    int n, k; cin >> n >> k;
    vi elements(n);
    rep(i, 0, n-1) 
        cin >> elements[i];
 
    set<int> notSeen;
    rep(i, 0, k-1) 
        notSeen.insert(i);
 
    map<int, int> cnt;
    rep(i, 0, k-1) {
        addNew(elements, cnt, notSeen, i, k);
    }
    cout << (notSeen.empty() ? k : *notSeen.begin()) << " ";

    rep(i, k, n-1) {
        removeOld(elements, cnt, notSeen, i-k);
        addNew(elements, cnt, notSeen, i, k);
        cout << (notSeen.empty() ? k : *notSeen.begin()) << " ";
    }
    
    
    return 0;
}
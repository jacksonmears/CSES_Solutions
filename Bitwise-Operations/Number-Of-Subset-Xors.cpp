#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
 
ll x;
ll basis[32];
int n, k = 0;
 
void insert_basis(ll x) {
    rep(b, 0, k) 
        x = min(x, x ^ basis[b]);
    if (x) {
        basis[k] = x;
        ++k;
    }
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    cin >> n;
    rep(i, 0, n-1) {
        cin >> x;
        insert_basis(x);
    }
 
    cout << (1 << k) << "\n";
}

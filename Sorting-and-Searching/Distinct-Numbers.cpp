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
 
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
    int n; cin >> n;
    ll x;
    set<ll> distinct_numbers;
    rep(i, 0, n-1) {
        cin >> x;
        distinct_numbers.insert(x);
    }
 
    cout << distinct_numbers.size();
 
    return 0;
}
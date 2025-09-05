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
 

constexpr int MAXN = 2e5+1;
int n;
ll machines[MAXN];
ll t, k, l = 0, r = 1e18, middle, sum, cur;


ll query(ll middle) {
    sum = 0;
    rep(machine, 0, n-1) {
        sum += middle/machines[machine];
        if (sum >= t) break;
    }
    return sum;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> t;
    rep(i, 0, n-1) 
        cin >> machines[i];

    middle = (r+l)/2;

    while (l < r) {
        cur = query(middle);
        cur >= t ? r = middle : l = middle+1;
        middle = (r+l)/2;
    }

    cout << middle;



    return 0;
}

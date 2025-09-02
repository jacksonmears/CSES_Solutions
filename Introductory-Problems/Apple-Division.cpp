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

int n;
ll min_diff = INT_MAX;
vi weights;


void dfs(ll left, ll right, int i) {
    if (i == weights.size()) {
        min_diff = min(min_diff, abs(left-right));
    } else {
        dfs(left+weights[i], right, i + 1);
        dfs(left, right+weights[i], i + 1); 
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    weights.assign(n, 0); 
    rep(i, 0, n-1) 
        cin >> weights[i];

    dfs(weights[0], 0, 1); 

    cout << min_diff;


    return 0;
}
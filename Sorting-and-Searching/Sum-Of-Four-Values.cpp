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


constexpr int MAXN = 1001;
int n;
ll x, a, need, elements[MAXN];

struct PAIRS {
    ll pair_sum;
    int idx1, idx2;
};
vector<PAIRS> pair_sums;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> x;
    rep(i, 0, n-1) 
        cin >> elements[i];

    rep(i, 0, n-1) {
        rep(j, i+1, n-1) {
            PAIRS z = {elements[i] + elements[j], i, j};
            pair_sums.pb(z);
        }
    }

    unordered_map<ll, vpl> seen;
    for (auto cur : pair_sums) {
        need = x - cur.pair_sum;
        if (seen.count(need)) {
            for (auto &[i2, j2] : seen[need]) {
                if (cur.idx1 != i2 && cur.idx1 != j2 && cur.idx2 != i2 && cur.idx2 != j2) {
                    cout << cur.idx1+1 << " " << cur.idx2+1 << " " << i2+1 << " " << j2+1;
                    return 0;
                }
            }
        }
        seen[cur.pair_sum].push_back({cur.idx1, cur.idx2});
    }

    cout << "IMPOSSIBLE\n";
    
    return 0;
}



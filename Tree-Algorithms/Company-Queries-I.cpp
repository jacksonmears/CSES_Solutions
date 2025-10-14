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
 
constexpr uint32_t MAXN = 2e5+1;
constexpr int32_t LOG2 = 18;
int binary_lifting[MAXN][LOG2];
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
 
	int n, q; cin >> n >> q;
	rep(i, 2, n) cin >> binary_lifting[i][0];

    // just for future reference. I had an OB error here by not subtracting 1 from LOG2 in the rep macro and took me so long to find it I resorted to ChatGPT... (and it couldn't find the simple error either...)
    // just a reminder how awful ai still is man holy moly literally an incredibly simple error that I SHOULD'VE found but neither did ai i'm so frustrated I actually took like 20 minutes to find it
	rep(i, 1, LOG2-1) {
		rep(node, 2, n) {
			binary_lifting[node][i] = binary_lifting[binary_lifting[node][i-1]][i-1];
		}
    }
 
    int x, k;
    rep(i, 0, q-1) {
        cin >> x >> k;
        repr(bit, LOG2, 0) {
            if ((1<<bit)&k) {
                x = binary_lifting[x][bit];
            }
        }
        cout << (x ? x : -1) << "\n";
    }

    
    return 0;
}
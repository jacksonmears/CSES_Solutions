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
    vi distance(n+1, 0);
    distance[1] = 0;
	rep(i, 2, n) {
        cin >> binary_lifting[i][0];
        distance[i] = distance[binary_lifting[i][0]]+1;
    }

	rep(i, 1, LOG2-1) {
		rep(node, 2, n) {
			binary_lifting[node][i] = binary_lifting[binary_lifting[node][i-1]][i-1];
		}
    }
 
    binary_lifting[1][0] = 1;
    int a, b;
    rep(i, 0, q-1) {
        cin >> a >> b;
        if (distance[b] < distance[a]) swap(a, b);
        int diff = distance[b]-distance[a];
        repr(bit, LOG2-1, 0) {
            if ((1<<bit)&diff) {
                b = binary_lifting[b][bit];
            }
        }


        while (a != b) {
            rep(bit, 1, LOG2-1) {
                if (binary_lifting[a][bit] == binary_lifting[b][bit]) {
                    a = binary_lifting[a][bit-1];
                    b = binary_lifting[b][bit-1];
                    break;
                }
            }
        }
        cout << a << "\n";
    }   

    
    return 0;
}
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



constexpr int MAXN = 2e5+1, MAXX = 1e6+1;
int inputs[MAXN];
bool divisors[MAXX];
int n;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);


    cin >> n; 
    int mx_divisor = 0;
    rep(i, 0, n-1) {
        cin >> inputs[i];
        if (divisors[inputs[i]]) mx_divisor = max(mx_divisor, inputs[i]);
        divisors[inputs[i]] = true;
    }

    rep(i, 0, n-1) if (inputs[i] > mx_divisor) {
        
        int cur = inputs[i];
        if (!(cur%(cur/2)) && divisors[cur/2]) {
            mx_divisor = max(mx_divisor, cur/2);
            continue;
        }

        repr(node, sqrt(cur), 2) {
            if (!(cur%node)) {
                if (divisors[node]) mx_divisor = max(mx_divisor, node);
                if (divisors[cur/node]) mx_divisor = max(mx_divisor, cur/node);
                divisors[node] = true;
                divisors[cur/node] = true;
            }
        }
    }



    cout << mx_divisor;
    
    return 0;
}


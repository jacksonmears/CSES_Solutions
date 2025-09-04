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
int n, x;
bool seen[MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n; 
    int counter = 0;
    rep(i, 0, n-1) {
        cin >> x;
        if (!seen[x-1]) ++counter;
        seen[x] = true;
    }
    
    cout << counter;

    return 0;
}

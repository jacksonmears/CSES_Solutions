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
int n, songs[MAXN], mx = 0, counter = 0, j;
ll k;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    set<ll> seen;
    rep(i, 0, n-1) 
        cin >> songs[i];
    
    rep(i, 0, n-1) {
        while (seen.contains(songs[i])) {
            --counter;
            seen.erase(songs[j]);
            ++j;
        }
        ++counter;
        mx = max(mx, counter);
        seen.insert(songs[i]);
    }

    cout << mx;

    return 0;
}


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

constexpr int MAXN = 2e5+2;
int n, q, reverseN; 
ll x, a, b;
int forw[MAXN], backw[MAXN];
set<ll> seenF, seenB;




int queryF() {
    return forw[b] - forw[a-1];
}

int queryB() {
    return backw[a] - backw[b+1];
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);


    cin >> n >> q;
    rep(i, 1, n) {
        cin >> x;
        reverseN = n-i+1;
        forw[i] = forw[i-1], backw[reverseN] = backw[reverseN+1];

        if (!seenF.count(x)) {
            ++forw[i];
            seenF.insert(x);
        }
        
        if (!seenB.count(x)) {
            ++backw[reverseN];
            seenB.insert(x);
        }
    }
    
    // cout << endl;
    // rep(i, 0, n+1) cout << forw[i] << " ";
    // cout << endl;
    // rep(i, 0, n+1) cout << backw[i] << " ";
    // cout << endl;
    
    rep(i, 0, q-1) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        cout << max(queryF(), queryB()) << "\n";
    }

    
    
    return 0;
}


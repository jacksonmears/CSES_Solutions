#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<bool> vb;
typedef vector<pl> vp;
typedef vector<vl> vvl;
constexpr ll MAX = 9e18;
constexpr ll MOD = 1e9 + 7;
constexpr int MAXN = 2e5+1;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (ll i = a; i <= b; i++)
#define repr(i, a, b) for (ll i = a; i >= b; i--)


ll n, m;
vvl courses;
bool seen[MAXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    courses = vvl(n+1);
    vl inDegrees(n+1, 0);
    rep(i, 0, m-1) {
        ll a, b; cin >> a >> b;
        courses[a].pb(b);
        inDegrees[b]++;
    }

    queue<ll> topography;
    rep(node, 1, n) {
        if (!inDegrees[node]) topography.push(node);
    }

    vl answer;

    while (!topography.empty()) {
        const ll node = topography.front(); topography.pop();
        answer.pb(node);
        seen[node] = true;
        for (const auto child : courses[node]) if (!seen[child]) {
            inDegrees[child]--;
            if (inDegrees[child] == 0) topography.push(child);
        }
    }


    if (answer.size() == n) {
        for (const auto node : answer) cout << node << " ";
    }
    else cout << "IMPOSSIBLE";


    return 0;
}


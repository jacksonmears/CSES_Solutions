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
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define repr(i, a, b) for (int i = a; i >= b; i--)



const int MAXN = 2e5+5;
int n, m;
vi edges[MAXN];
stack<int> path;

void dfs(int& node) {
    while (!edges[node].empty()) {
        int child = edges[node].back();
        edges[node].pop_back();
        dfs(child);
    }
    path.push(node);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    vector<int> indeg(n+1), outdeg(n+1);

    rep(i, 0, m-1) {
        int a, b; cin >> a >> b;

        edges[a].pb(b);
        outdeg[a]++;
        indeg[b]++;
    }

    if (outdeg[1] != indeg[1] + 1 || indeg[n] != outdeg[n] + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    rep(i, 2, n-1) {
        if (indeg[i] != outdeg[i]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    int starting_node = 1;
    dfs(starting_node);

    if ((int)path.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }

    return 0;
}
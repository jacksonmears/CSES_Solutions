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


constexpr int MAXN = 505;
int n, m;
vi edges[MAXN];
vector<list<int>> paths;
list<int> current_path;
bool seen[MAXN];

bool dfs(int node) {
    if (seen[node]) return false;

    current_path.pb(node);
    
    if (node == n) {
        paths.pb(current_path);
        current_path.pop_back();
        return true;
    }

    for (auto child : edges[node]) {
        if (dfs(child)) {
            seen[node] = true;
            current_path.pop_back();
            return true;
        }
    }

    return false;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    rep(i, 0, m-1) {
        int a, b; cin >> a >> b;
        edges[a].pb(b);
    }

    for (auto child : edges[1]) {
        current_path.clear();
        current_path.pb(1);
        dfs(child);
    }

    cout << paths.size() << "\n";
    for (auto path : paths) {
        cout << path.size() << "\n";
        auto it = path.begin();
        while (it != path.end()) {
            cout << *it << " ";
            it++;
        }
        cout << endl;
    }


    return 0;
}


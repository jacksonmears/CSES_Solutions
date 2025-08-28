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


const int MAXN = 505;
vi edges[MAXN];
int matchGirl[MAXN], matchBoy[MAXN];
bool visited[MAXN];


bool dfs(int boy) {

    for (int girl : edges[boy]) {
        if (visited[girl]) continue;
        
        visited[girl] = true;
        if (matchGirl[girl] == -1 || dfs(matchGirl[girl])) {
            matchGirl[girl] = boy;
            matchBoy[boy] = girl;
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;

    rep(i, 0, k-1) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b); 
    }

    ranges::fill(matchGirl, -1);
    ranges::fill(matchBoy, -1);

    int maxPairs = 0;
    rep(boy, 1, n) {
        ranges::fill(visited, false);
        if (dfs(boy)) maxPairs++;
    }

    cout << maxPairs << "\n";
    rep(girl, 1, m) {
        if (matchGirl[girl] != -1) {
            cout << matchGirl[girl] << " " << girl << "\n";
        }
    }
}

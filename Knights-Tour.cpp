#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
constexpr ll MAX = 9e18;
constexpr ll MOD = 1e9 + 7;

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (ll i = a; i <= b; i++)


ll n, m;
vector<pl> moves = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
vector<vl> board;

bool isValid(const ll x, const ll y) {
    return x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 0;
}

int countOnwardMoves(const ll x, const ll y) {
    ll countMoves = 0;
    for (auto &[dx, dy] : moves) {
        ll nx = x + dx, ny = y + dy;
        if (isValid(nx, ny)) countMoves++;
    }
    return countMoves;
}

bool dfs(const ll x, const ll y, const ll moveNumber) {
    board[x][y] = moveNumber;

    if (moveNumber == n * m) return true;

    vector<tuple<ll, ll, ll>> Warnsdorff;

    for (auto &[dx, dy] : moves) {
        ll nx = x + dx, ny = y + dy;
        if (isValid(nx, ny)) {
            ll onward = countOnwardMoves(nx, ny);
            Warnsdorff.emplace_back(onward, nx, ny);
        }
    }

    ranges::sort(Warnsdorff);

    for (auto &[_, nx, ny] : Warnsdorff) {
        if (dfs(nx, ny, moveNumber + 1)) return true;
    }

    board[x][y] = 0;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    board = vector<vl>(n, vl(m, 0));

    if (dfs(0, 0, 1)) {
        rep(i, 0, n-1) {
            rep(j, 0, m-1)
                cout << board[i][j] << ' ';
            cout << '\n';
        }
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}

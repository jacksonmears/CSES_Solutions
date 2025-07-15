#include <bits/stdc++.h>
#include <regex>
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
#define REP(i,a,b) for (ll i = a; i <= b; i++)





int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n; cin >> n;
    vector<string> grid(n);
    REP(i, 0, n-1) cin >> grid[i];

    string result;
    vector<pl> positionsExploring = {{0, 0}};
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[0][0] = true;
    result += grid[0][0];



    for (ll step = 1; step < 2 * n - 1; ++step) {
        char min_char = 'Z' + 1;
        vector<pl> nextPosition;


        // for each position in the grid we check the bottom and right position
        // if they match then we add them both to positionsExploring and continue to do so until one is found (using BFS in this DP problem)
        for (auto [currentX, currentY] : positionsExploring) {
            for (auto [potentialNextX, potentialNextY] : vector<pl>{{1, 0}, {0, 1}}) {      // looking at cell below and right of current position
                ll newX = currentX + potentialNextX, newY = currentY + potentialNextY;
                if (newX < n && newY < n) {
                    char c = grid[newX][newY];
                    if (!visited[newX][newY]) {
                        if (c < min_char) {
                            min_char = c;
                            nextPosition.clear();
                            nextPosition.emplace_back(newX, newY);
                        } else if (c == min_char) {
                            nextPosition.emplace_back(newX, newY);
                        }
                        visited[newX][newY] = true;
                    }
                }
            }
        }
        result += min_char;
        positionsExploring = move(nextPosition);
    }

    cout << result << '\n';
    return 0;
}


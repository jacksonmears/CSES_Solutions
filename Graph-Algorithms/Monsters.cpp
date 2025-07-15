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


ll n, m;
vector<string> grid;
vector<vl> monster_time, player_time;
vector<vector<pl>> previous_move;

const vector<pl> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const vector<char> directions_char = {'D', 'R', 'U', 'L'};

bool in_bounds(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void bfs_monsters(queue<pl>& monster_queue) {
    while (!monster_queue.empty()) {
        auto [x, y] = monster_queue.front(); monster_queue.pop();
        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (in_bounds(nx, ny) && grid[nx][ny] != '#' && monster_time[nx][ny] > monster_time[x][y] + 1) {
                monster_time[nx][ny] = monster_time[x][y] + 1;
                monster_queue.push({nx, ny});
            }
        }
    }
}

bool bfs_player(pl start) {
    queue<pl> player_queue;
    player_queue.push(start);
    player_time[start.first][start.second] = 0;

    while (!player_queue.empty()) {
        auto [x, y] = player_queue.front(); player_queue.pop();

        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            vector<char> path;
            while (previous_move[x][y] != pl(-1, -1)) {
                auto [px, py] = previous_move[x][y];
                for (int d = 0; d < 4; ++d) {
                    if (x - directions[d].first == px && y - directions[d].second == py) {
                        path.push_back(directions_char[d]);
                        break;
                    }
                }
                x = px;
                y = py;
            }

            reverse(path.begin(), path.end());
            cout << "YES\n" << path.size() << "\n";
            for (char c : path) cout << c;
            cout << "\n";
            return true;
        }

        REP(direction, 0, 3) {
            int nx = x + directions[direction].first;
            int ny = y + directions[direction].second;
            if (in_bounds(nx, ny) && grid[nx][ny] != '#' && player_time[nx][ny] == INT_MAX) {
                int arrival = player_time[x][y] + 1;
                if (arrival < monster_time[nx][ny]) {
                    player_time[nx][ny] = arrival;
                    previous_move[nx][ny] = {x, y};
                    player_queue.push({nx, ny});
                }
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    grid.resize(n);
    monster_time = vector<vl>(n, vl(m, INT_MAX));
    player_time = vector<vl>(n, vl(m, INT_MAX));
    previous_move.assign(n, vector<pl>(m, {-1, -1}));

    pl start;
    queue<pl> monster_q;

    REP(i, 0, n-1) {
        cin >> grid[i];
        REP(j, 0, m-1) {
            if (grid[i][j] == 'A') start = {i, j};
            else if (grid[i][j] == 'M') {
                monster_q.push({i, j});
                monster_time[i][j] = 0;
            }
        }
    }

    bfs_monsters(monster_q);

    if (!bfs_player(start)) {
        cout << "NO\n";
    }

    return 0;
}

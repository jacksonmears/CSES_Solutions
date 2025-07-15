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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m; cin >> n >> m;

    vector<vector<pl>> adjacency_matrix_weighted(n + 1);
    for (ll i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        adjacency_matrix_weighted[a].emplace_back(b, c);
    }

    vector<ll> minimum_distance(n + 1, LLONG_MAX);
    vector<ll> number_of_ways_for_distance(n + 1, 0);
    vector<ll> min_flights(n + 1, LLONG_MAX);
    vector<ll> max_flights(n + 1, LLONG_MIN);

    priority_queue<pl, vector<pl>, greater<pl>> pq;

    minimum_distance[1] = 0; number_of_ways_for_distance[1] = 1;
    min_flights[1] = 0; max_flights[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [current_distance, current_node] = pq.top(); pq.pop();
        if (current_distance > minimum_distance[current_node]) continue;

        for (auto [next_node, next_weight] : adjacency_matrix_weighted[current_node]) {
            if (minimum_distance[current_node] + next_weight < minimum_distance[next_node]) {
                minimum_distance[next_node] = minimum_distance[current_node] + next_weight;
                number_of_ways_for_distance[next_node] = number_of_ways_for_distance[current_node];
                min_flights[next_node] = min_flights[current_node] + 1;
                max_flights[next_node] = max_flights[current_node] + 1;
                pq.push({minimum_distance[next_node], next_node});
            }
            else if (minimum_distance[next_node] == minimum_distance[current_node] + next_weight) {
                number_of_ways_for_distance[next_node] = (number_of_ways_for_distance[next_node] + number_of_ways_for_distance[current_node]) % MOD;
                min_flights[next_node] = min(min_flights[next_node], min_flights[current_node] + 1);
                max_flights[next_node] = max(max_flights[next_node], max_flights[current_node] + 1);
            }
        }
    }

    cout << minimum_distance[n] << " " << number_of_ways_for_distance[n] << " " << min_flights[n] << " " << max_flights[n] << "\n";

    return 0;
}


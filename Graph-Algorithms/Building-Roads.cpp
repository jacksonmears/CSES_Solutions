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
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)

unordered_set<ll> seen;
vector<vl> roads;
vl components;

void dfs(const ll city) {
    seen.insert(city);
    for (ll neighbor : roads[city]) {
        if (!seen.contains(neighbor)) dfs(neighbor);
    }
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll n, m; cin >> n >> m;
    roads = vector<vl> (n+1);
    REP(i, 0, m-1) {
        ll a, b; cin >> a >> b;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }


    REP(city, 1, n) {
        if (!seen.contains(city)) {
            components.push_back(city);
            dfs(city);
        }
    }


    cout << components.size()-1 << '\n';
    REP(i, 1, components.size()-1) {
        cout << components[0] << " " << components[i] << "\n";
    }




    return 0;
}
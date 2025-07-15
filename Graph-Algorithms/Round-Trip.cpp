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
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)

vl roads[100005];
bool seen[100005];
vl cycle;
ll n, m;

bool dfs(const ll mainCity, const ll parentCity){
    seen[mainCity] = 1;
    for (auto i: roads[mainCity]) {
        cycle.pb(i);
        if (!seen[i]) {
            if (dfs(i, mainCity)) return true;
        } else if (i != parentCity) {
            return true;
        }
        cycle.pop_back();
    }
    return false;
}


void solve(){
    REP(i,0,m-1){
        ll a,b; cin >> a >> b;
        roads[a].pb(b), roads[b].pb(a);
    }

    REP(i,1,n){
        cycle.pb(i);
        if (!seen[i] && dfs(i,0)){
            vl currentCycle; currentCycle.pb(cycle.back());
            for (ll i = cycle.size()-2; i >= 0; i--) {
                currentCycle.pb(cycle[i]);
                if (cycle[i] == cycle.back()) break;
            }
            cout << currentCycle.size() << "\n";
            for (auto city: currentCycle)  cout << city << " ";
            return;
        }
        cycle.pop_back();
    }
    cout << "IMPOSSIBLE";

}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    solve();

    return 0;
}
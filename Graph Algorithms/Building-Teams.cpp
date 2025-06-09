#include <bits/stdc++.h>
#include <regex>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
const int maxN = 1e5+1;
constexpr ll MOD = 1e9 + 7;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)




bool possible, visited[maxN], team[maxN];
vl connections[maxN];

void dfs(ll currentNode){
    for(ll friendNode : connections[currentNode]){
        if(!visited[friendNode]){
            team[friendNode] = !team[currentNode];
            visited[friendNode] = true;
            dfs(friendNode);
        } else if(team[friendNode] == team[currentNode]) possible = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll n, m; cin >> n >> m;

    REP(i, 0, m-1) {
        ll a, b; cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    possible = true;
    REP(i, 0, n-1) if (possible) {
        if(!visited[i]){
            visited[i] = true;
            dfs(i);
        }
    }

    if(!possible) cout << "IMPOSSIBLE";
    else for(int i = 1; i <= n; i++) cout <<  (team[i] ? 1 : 2) << " ";


    return 0;
}

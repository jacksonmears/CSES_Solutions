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

vector<vl> relationshipTree;
unordered_set<ll> parents;

void solve() {
    vl orderOfCourses;
    queue<ll> bfs; for (auto course : parents) bfs.push(course);
    unordered_set<ll> visited;
    while(!bfs.empty()) {
        if (!visited.contains(bfs.front())) {
            orderOfCourses.pb(bfs.front()); visited.insert(bfs.front());
            for (auto child : relationshipTree[bfs.front()]) bfs.push(child);
        }
        bfs.pop();
    }

    if (orderOfCourses.size() != relationshipTree.size()-1) cout << "IMPOSSIBLE";
    else {
        for (auto course : orderOfCourses) cout << course << " ";
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n, m; cin >> n >> m;
    relationshipTree = vector<vl>(n+1);
    REP(i, 0, m-1) {
        ll a, b; cin >> a >> b;
        relationshipTree[a].pb(b);
        if (parents.contains(b)) parents.erase(b);
        parents.insert(a);
    }

    solve();

    return 0;
}

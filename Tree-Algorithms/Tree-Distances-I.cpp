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

ll n;
vector<vl> adjacencyMatrix;
vector<vl> maxDistance; //each node tracks the max distance from both ends of tree (could be formatted as a tuple but vl works just fine)

void dfs(const ll parent, const ll node, const ll distance, const ll whichEnd)
{
    maxDistance[node][whichEnd] = distance;

    for (auto child : adjacencyMatrix[node])
            if (child != parent)
                dfs(node, child, distance + 1, whichEnd);
}

//using bfs to find diameter of tree
ll findFurthestNode(ll node) {

    queue<pl> q; q.emplace(node, 0);

    vector<bool> seen(n+1, false); seen[node] = true;
    maxDistance = vector<vl>(n + 1, vl(2, 0));

    ll currentNode;
    while (!q.empty()) {
        currentNode = q.front().first;
        ll distance = q.front().second;
        q.pop();

        for (auto child : adjacencyMatrix[currentNode]) {
            if (!seen[child]) {
                q.emplace(child, distance+1);
                seen[child] = true;
            }
        }
    }
    //return the last node
    return currentNode;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    adjacencyMatrix = vector<vl> (n+1);
    REP(i, 0, n-2) {
        ll a, b; cin >> a >> b;
        adjacencyMatrix[a].pb(b); adjacencyMatrix[b].pb(a);
    }

    ll furthestNodeFromOne = findFurthestNode(1);
    ll furthestNodeFromEnd = findFurthestNode(furthestNodeFromOne);


    dfs(0, furthestNodeFromOne, 0, 0);
    dfs(0, furthestNodeFromEnd, 0, 1);


    REP(i, 1, n)
        cout << max(maxDistance[i][0], maxDistance[i][1]) << " ";





    return 0;
}
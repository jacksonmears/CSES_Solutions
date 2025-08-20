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



const int MAXN = 2e5+1;

bool seen[MAXN];
int edges[MAXN], inDegrees[MAXN], dp[MAXN];
vi reverse_edges[MAXN];
queue<int> topological;

void propogate(const int node){
    for(const int parent : reverse_edges[node]){
        if(!seen[parent]){
            dp[parent] = dp[node]+1;
            seen[parent] = true;
            propogate(parent);
        }
    }
}

void fetch_distance(const int node, const int distance = 1){
    seen[node] = true;
    int child = edges[node];
    if(seen[child]){
        dp[node] = distance;
    } else {
        fetch_distance(child, distance+1);
        dp[node] = dp[child];
    }
    propogate(node);
}


// BABY KOSARAJU implementation !

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    rep(node, 1, n) {
        int child; cin >> child;
        edges[node] = child;
        reverse_edges[child].pb(node);
        inDegrees[child]++;
    }

    rep(node, 1, n)
        if(inDegrees[node] == 0)
            topological.push(node);

    while(!topological.empty()){
        const int node = topological.front(); topological.pop();
        const int child = edges[node];
        inDegrees[child]--;
        if(inDegrees[child] == 0)
            topological.push(child);
    }

    rep(node, 1, n)
        if(inDegrees[node] && !seen[node])
            fetch_distance(node);

    rep(node, 1, n)
        cout << dp[node] << " ";

    return 0;
}


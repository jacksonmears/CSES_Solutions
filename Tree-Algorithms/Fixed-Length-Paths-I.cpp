#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
typedef vector<char> vc;
constexpr int MOD = 1e9 + 7;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = a; i >= b; --i)

constexpr int MAXN = 2e5+1;
int n, k, maxDepth, subtreeSize[MAXN], cnt[MAXN];
bool seen[MAXN];
ll ans;
vi adj_matrix[MAXN];

int dfsSubtreeSize(int node = 1, int parent = -1){
    subtreeSize[node] = 1;
    for(int child : adj_matrix[node]) if(child != parent && !seen[child]) {
        subtreeSize[node] += dfsSubtreeSize(child, node);
    }

    return subtreeSize[node];
}

int dfsCentroid(int node, int parent, int currentSubtreeSize){
    for(int child : adj_matrix[node]) {
        if(child != parent && !seen[child] && subtreeSize[child] > currentSubtreeSize/2)
            return dfsCentroid(child, node, currentSubtreeSize);
    }

    return node;
}




void dfsPathsAddToAnswer(int node, int parent, int currentDistance){
    if(currentDistance > k) return;

    maxDepth = max(maxDepth, currentDistance);
    ans += cnt[k-currentDistance];

    for(int child : adj_matrix[node]) if(child != parent && !seen[child]) {
        dfsPathsAddToAnswer(child, node, currentDistance+1);
    }

}

void dfsPathsPrepare(int node, int parent, int currentDistance){
    if(currentDistance > k) return;

    maxDepth = max(maxDepth, currentDistance);
    ++cnt[currentDistance];

    for(int child : adj_matrix[node]) if(child != parent && !seen[child]) {
        dfsPathsPrepare(child, node, currentDistance+1);
    }

}

void solve(int node){
    int centroid = dfsCentroid(node, -1, dfsSubtreeSize(node));
    seen[centroid] = true;
    maxDepth = 0;

    // Process each child of the centroid in two steps:
    // 1. Count how many pairs this subtree’s nodes can form with nodes already seen (in previous subtrees)
    // 2. Record this subtree’s nodes in cnt[] for future subtrees to use
    // This ensures we count each pair exactly once without double-counting
    for(int child : adj_matrix[centroid]) if(!seen[child]) {
        dfsPathsAddToAnswer(child, centroid, 1); // add how many valid pairs exist
        dfsPathsPrepare(child, centroid, 1); // once done adding the subtree pairs we record all counts of the node distance into cnt[] so the next subtree can use them for conuting
    }
    fill(cnt+1, cnt+maxDepth+1, 0);

    for(int child : adj_matrix[centroid]) if(!seen[child]) {
        solve(child);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> k;
    int a, b;
    rep(i, 0, n-2) {
        cin >> a >> b;
        adj_matrix[a].pb(b);
        adj_matrix[b].pb(a);
    }

    cnt[0] = 1;
    solve(1);

    cout << ans;

    return 0;
}
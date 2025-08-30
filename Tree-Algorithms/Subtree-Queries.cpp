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

int n, q, a, b, t, s, timer;
int in[MAXN], out[MAXN];
ll node_values[MAXN], fenwick[2*MAXN];
vi edges[MAXN];

void update(int index, ll value){
    for(int i = index; i < 2*MAXN; i += i&-i)
        fenwick[i] += value;
}

ll query(int index){
    ll sum = 0;
    for(int i = index; i > 0; i -= i&-i)
        sum += fenwick[i];
    return sum;
}

void dfs(int node, int parent){
    in[node] = ++timer;
    for(int neighbor : edges[node])
        if(neighbor != parent)
            dfs(neighbor, node);
    out[node] = ++timer;
}


// idea is to transfer tree into 1D array where we can quickly perform queries with fenwick/BIT
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> q;
    rep(i, 1, n)
        cin >> node_values[i];

    rep(i, 0, n-2) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    timer = 0;
    dfs(1, -1);

    rep(i, 1, n)
        update(out[i], node_values[i]);

    rep(i, 0, q-1) {
        cin >> t >> s;
        if(t == 1){
            int new_value; cin >> new_value;
            update(out[s], new_value - node_values[s]);
            node_values[s] = new_value;

        } else if(t == 2){
            cout << query(out[s])-query(in[s]) << "\n";
        }
    }
}
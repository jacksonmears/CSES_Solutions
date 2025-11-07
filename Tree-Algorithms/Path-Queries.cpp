#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#if __has_include("../include/print_ostream.h")
    #include "../include/print_ostream.h"
#endif
using namespace std;
 
using ll = uint64_t;
 
using vi = vector<int32_t>;
using vvi = vector<vi>;
using pi = pair<int32_t, int32_t>;
using vpi = vector<pi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using vb = vector<bool>;
using vc = vector<char>;
 
#define pb push_back
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define repr(i,a,b) for (int i = a; i >= b; --i)
 
constexpr uint32_t MOD = 1e9 + 7;
 
constexpr int MAXN = 2e5+1;

class F {
public:

    F() {}
    F(int n_, int m_) : n(n_), m(m_) {
        values = vi(n+1);
        edges = vvi(n+1);
        chain = vi(n+1);
        chainPos = vi(n+1);
        parent = vi(n+1);
        heavy.set(1);
    }

    void parseValues() {
        rep(i, 1, n) cin >> values[i];

        rep(i, 1, n-1) {
            int a, b; cin >> a >> b;
            edges[a].pb(b);
            edges[b].pb(a);
        }
    }

    int heavyNodesInit(int node, int parent_node) {
        
        int subtree_size = 1;
        pi mx {0,0};
        for (int child : edges[node]) if (child != parent_node) {
            parent[child] = node;
            subtree_size += heavyNodesInit(child, node);
            if (subtree_size>mx.first) {
                mx.first = subtree_size;
                mx.second = child;
            }
        }
        heavy.set(mx.second);
    
        return subtree_size;
    }

    void heavyChainsInit(int node, int parent_node) {
        if (heavy[node]) {
            if (heavy[parent_node]) {
                chain[node] = chain[parent_node];
                chainPos[node] = chainPos[parent_node]+1;
                fenwickChains[chain[node]].pb(node);
            }
            else {
                chain[node] = chainCnt++;
                chainPos[node] = 1;
                fenwickChains.pb({0, (ll)node});
                chainHead.pb(node);
            }
        }
    
        for (int child : edges[node]) if (child != parent_node) {
            heavyChainsInit(child, node);
        }
    
    }

    void updateFenwick(vl& fenwick, int index, int value) {
        fenwick[index] = 0;
        for (size_t i = index; i < fenwick.size(); i+=i&-i)
            fenwick[i] += value;
        
    }
    
    
    void fenwickInit() {
        for (vl& fenwick : fenwickChains)
            repr(i, fenwick.size()-1, 1) 
                updateFenwick(fenwick, i, values[fenwick[i]]);
    }

    void handle1(int node) {
        int x; cin >> x;
    
        int old = values[node];
        values[node] = x;
    
        if (heavy[node]) {
            vl& fenwick = fenwickChains[chain[node]];
            for (size_t i = chainPos[node]; i < fenwick.size(); i+=i&-i) {
                fenwick[i]-=old;
                fenwick[i]+=x;
            }
        }
    }
    
    void handle2(int node) {
        ll sum = 0;
    
        while (node) {
            if (heavy[node]) {
                vl& fenwick = fenwickChains[chain[node]];
                for (int i = chainPos[node]; i > 0; i-=i&-i) {
                    sum += fenwick[i];
                }
                node = parent[chainHead[chain[node]]];
            }
            else {
                sum += values[node];
                node = parent[node];
            }
        }
    
        cout << sum << "\n";
    }

    void heavyReset0() {
        heavy.reset(0);
    }

    ~F(){}

private:
    int n, m;
    vi values;
    vvi edges;
    int chainCnt = 0;
    vi chain;
    vi chainPos;
    vi parent;
    vi chainHead;
    vvl fenwickChains;
    bitset<MAXN> heavy;
};
 
 
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    int n, m; cin >> n >> m;
 
    F f{n, m};

    f.parseValues();

    f.heavyNodesInit(1, 0);
    
    f.heavyReset0();
    f.heavyChainsInit(1, 0);

    f.fenwickInit();

    rep(i, 1, m) {
        int q, s; cin >> q >> s;
        if (q == 1) f.handle1(s);
        else f.handle2(s);
    }
    
    return 0;
}
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


vector<vl> trie(1, vl(2));

void insert_trie(const ll x) {
    ll node = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = (x >> i)&1;
        if (!trie[node][bit]) {
            trie.push_back({0,0});
            trie[node][bit] = trie.size()-1;
        }
        node = trie[node][bit];
    }
}

int query(int x) {
    int node = 0, result = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = (x >> i) & 1;
        int opposite = bit ^ 1;
        if (trie[node][opposite]) {
            result |= (1 << i);
            node = trie[node][opposite];
        } else {
            node = trie[node][bit];
        }
    }
    return result;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n; cin >> n;
    vl prefix_xor(n+1); prefix_xor[0] = 0;
    vector<vl> elements_in_binary(n+1);
    REP(i, 1, n) {
        ll x; cin >> x;
        prefix_xor[i] = x^prefix_xor[i-1];
    }


    int max_result = 0;
    insert_trie(0);

    REP(i, 1, n) {
        int current = prefix_xor[i];
        max_result = max(max_result, query(current));
        insert_trie(current);
    }

    cout << max_result << "\n";



    return 0;
}



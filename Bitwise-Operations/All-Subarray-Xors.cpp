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
#define rep(i,a,b) for (ll i = a; i <= b; i++)


vector<ll> basis;

void insert_basis(ll x) {
    for (auto b : basis)
        x = min(x, x ^ b);
    if (x) basis.push_back(x);
}

void generate_all_xors(int idx, ll current, vector<ll> &basis, vector<ll> &result) {
    if (idx == (int)basis.size()) {
        result.push_back(current);
        return;
    }
    generate_all_xors(idx+1, current, basis, result);
    generate_all_xors(idx+1, current ^ basis[idx], basis, result);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    ll prefix = 0;
    insert_basis(prefix);  // Insert 0

    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        prefix ^= x;
        insert_basis(prefix);
    }

    vector<ll> result;
    generate_all_xors(0, 0, basis, result);

    sort(result.begin(), result.end());

    cout << (int)result.size() << "\n";
    for (auto &x : result) cout << x << " ";
    cout << "\n";

    return 0;
}

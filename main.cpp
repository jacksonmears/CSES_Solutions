#include <bits/stdc++.h>
#include <regex>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
constexpr ll MAX = 9e18;
constexpr ll MOD = 1e9 + 7;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)


set<string> results;
vector<pair<char, char>> queries;

void dfs(string s, int idx) {
    if (idx == queries.size()) {
        results.insert(s);
        return;
    }

    char x = queries[idx].first;
    char y = queries[idx].second;

    dfs(s, idx + 1);

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == x) {
            string new_s = s;
            new_s[i] = y;
            dfs(new_s, idx + 1);
            break;
        }
    }

}

void solve() {
    results.clear();
    queries.clear();

    ll n, q;
    string s;
    cin >> n >> q >> s;

    REP(i, 0, q - 1) {
        char x, y;
        cin >> x >> y;
        queries.emplace_back(x, y);
    }

    dfs(s, 0);
    cout << *results.begin() << '\n';
}




int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);


    ll t; cin >> t;
    while (t--) {
        solve();
    }


    return 0;
}
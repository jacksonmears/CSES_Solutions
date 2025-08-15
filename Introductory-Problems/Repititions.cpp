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





int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);


    string s; cin >> s;
    ll max_rep = 1, current_repetitions = 1;
    REP(i, 1, s.size()-1) {
        if (s[i] == s[i-1]) {
            current_repetitions++;
            max_rep = max(current_repetitions, max_rep);
        }
        else current_repetitions = 1;

    }

    cout << max_rep;

    return 0;
}
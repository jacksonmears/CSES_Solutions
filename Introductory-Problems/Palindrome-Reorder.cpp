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

    unordered_map<char, ll> mp; REP(i, 0, s.size()-1) mp[s[i]]++;
    ll cntOdd = 0; char oddChar = '{';

    for (auto &i : mp) {
        if (i.second&1) {
            cntOdd++;
            oddChar = i.first;
        }
    }
    if (cntOdd != (s.size()&1)) return cout << "NO SOLUTION", 0;
    string ans = "";

    auto it = mp.begin();
    while (it != mp.end()) {
        if (it->first != oddChar) {
            for (ll i = 0; i < it->second/2; i++) ans.push_back(it->first);
        }
        it++;
    }
    if (cntOdd) for (ll i = 0; i < mp[oddChar]; i++) ans.push_back(oddChar);
    ll reverseIndex = ll(s.size())/2 - mp[oddChar]/2 -1;

    for (ll i = reverseIndex; i >= 0; i--) ans.push_back(ans[i]);
    cout << ans << endl;


    return 0;
}
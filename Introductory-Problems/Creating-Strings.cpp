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


set<string> answers;

void dfs(string current_string, string remaining_letters) {
    if (remaining_letters.empty()) {
        answers.insert(current_string);
        return;
    }

    for (ll i = 0; i < remaining_letters.size(); i++) {
        string next_string = current_string + remaining_letters[i];
        string next_remaining = remaining_letters.substr(0, i) + remaining_letters.substr(i + 1);
        dfs(next_string, next_remaining);
    }
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string s; cin >> s;
    dfs("", s);

    cout << answers.size() << '\n';
    for (auto answer : answers) {
        cout << answer << '\n';
    }

    return 0;
}
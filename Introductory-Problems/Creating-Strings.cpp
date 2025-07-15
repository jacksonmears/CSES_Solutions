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


set<string> listOfAnswers;

void dfs(string currentString, string remainingLetters) {
    if (remainingLetters.empty()) {
        listOfAnswers.insert(currentString);
        return;
    }

    for (ll i = 0; i < remainingLetters.size(); i++) {
        string nextString = currentString + remainingLetters[i];
        string nextRemaining = remainingLetters.substr(0, i) + remainingLetters.substr(i + 1);
        dfs(nextString, nextRemaining);
    }
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    string s; cin >> s;

    dfs("", s);

    cout << listOfAnswers.size() << '\n';
    for (auto i : listOfAnswers) {
        cout << i << '\n';
    }

    return 0;
}
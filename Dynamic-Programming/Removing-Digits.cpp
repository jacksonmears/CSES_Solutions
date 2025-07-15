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

    ll n; cin >> n;
    vl dynamicProgramming(n+1); dynamicProgramming[0] = 0;

    REP(i, 1, n) {
        ll temporaryVariable = i, optimalSolution = INT_MAX;
        set<ll> possibleNumbersToSubtract;
        while (temporaryVariable && possibleNumbersToSubtract.size() < 10) {
            possibleNumbersToSubtract.insert(temporaryVariable%10);
            temporaryVariable /= 10;
        }
        for (ll digit : possibleNumbersToSubtract) if (digit) {
            optimalSolution = min(optimalSolution, dynamicProgramming[i-digit]);
        }
        dynamicProgramming[i] = optimalSolution+1;
    }

    cout << dynamicProgramming[n];


    return 0;
}
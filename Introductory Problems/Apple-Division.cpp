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


ll minimumDifference = INT_MAX;


void dfs(ll leftSum, ll rightSum, vl& listOfWeights, ll indexOfWeights) {
    if (indexOfWeights == listOfWeights.size()) {
        minimumDifference = min(minimumDifference, abs(leftSum-rightSum));
    } else {
        dfs(leftSum+listOfWeights[indexOfWeights], rightSum, listOfWeights, indexOfWeights + 1);
        dfs(leftSum, rightSum+listOfWeights[indexOfWeights], listOfWeights, indexOfWeights + 1);
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll n; cin >> n;
    vl listOfWeights(n); REP(i, 0, n-1) cin >> listOfWeights[i];

    dfs(0, 0, listOfWeights, 0);

    cout << minimumDifference;


    return 0;
}
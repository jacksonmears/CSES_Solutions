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

const int maxN = 5000;

ll n, rawList[maxN+1];
ll prefixSum[maxN+1], dynamicProgramming[maxN+1][maxN+1];
bool visited[maxN+1][maxN+1];

ll sum(const ll left, const ll right){
	return prefixSum[right] - prefixSum[left-1];
}

ll solve(const ll left, const ll right){
	if(visited[left][right]) return dynamicProgramming[left][right];
	if(left == right) return rawList[left];
	visited[left][right]=true;
	return dynamicProgramming[left][right] = max(rawList[left]+sum(left+1, right)-solve(left+1, right), rawList[right]+sum(left,right-1)-solve(left,right-1));
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n;
	REP(i, 1, n) {
		cin >> rawList[i];
		prefixSum[i] = prefixSum[i-1] + rawList[i];
	}
	cout << solve(1, n);

    return 0;
}


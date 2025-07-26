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


struct triplet {
    ll start, finish, reward;
};

bool compareProject(const triplet& a, const triplet& b) {
    return a.finish < b.finish;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll n; cin >> n;
    vector<triplet> projects(n);
    rep(i, 0, n-1) {
        ll a, b, w; cin >> a >> b >> w;
        projects[i] = {a, b, w};
    }
    ranges::sort(projects.begin(), projects.end(), compareProject);

    vl ended(n); rep(i, 0, n-1) ended[i] = projects[i].finish;

    vl dp(n+1, 0);
    rep(i, 1, n) {
        triplet project = projects[i-1];
        auto it = upper_bound(ended.begin(), ended.end(), project.start-1)-ended.begin();
        dp[i] = max(dp[i-1], dp[it]+project.reward);
    }

    cout << dp[n];



    return 0;
}

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



int editDistDP(string& str1, string& str2, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) dp[i][j] = j;

            else if (j == 0) dp[i][j] = i;

            else if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j]),dp[i - 1][j - 1]);
        }
    }

    return dp[m][n];
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);


    string n, m; cin >> n >> m;

    cout << editDistDP(n, m, n.length(), m.length());




    return 0;
}
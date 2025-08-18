#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<bool> vb;
typedef vector<pl> vp;
typedef vector<vl> vvl;
constexpr ll MAX = 9e18;
constexpr ll MOD = 1e9 + 7;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (ll i = a; i <= b; i++)
#define repr(i, a, b) for (ll i = a; i >= b; i--)


const ll MAXN = 20;

bool tight[MAXN];
ll dp[10][MAXN];

ll solve(ll value){
    if(value <= 10) return value;

    vl digits;
    memset(dp, 0, sizeof(dp));
    memset(tight, 0, sizeof(tight));

    while (value) {
        digits.push_back(value%10);
        value /= 10;
    }
    ranges::reverse(digits);
    const ll N = (ll)digits.size();

    tight[0] = true;
    rep(i, 1, N-1)
        tight[i] = tight[i-1] && (digits[i] != digits[i-1]);

    rep(digit, 1, digits[0])
        dp[digit][0] = 1;

    rep(i, 1, N-1) {
        if(tight[i-1])
            rep(digit, 0, digits[i])
                if(digit != digits[i-1])
                    dp[digit][i]++;

        rep(digit, 1, 9)
            dp[digit][i]++;

        rep(digit1, 0, 9)
            rep(digit2, 0, 9)
                if(digit1 != digit2)
                    dp[digit2][i] += dp[digit1][i-1];
    }

    ll count = tight[N-1];
    rep(digit, 0, 9)
        count += dp[digit][N-1];
    return count;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll a, b; cin >> a >> b;
    cout << solve(b) - solve(a-1);
}


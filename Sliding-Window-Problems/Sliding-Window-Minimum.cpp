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

deque<ll> minimumStack;
vl inputArray;

void updateStack(const ll i) {
    while (!minimumStack.empty() && minimumStack.back() > inputArray[i]) {
        minimumStack.pop_back();
    }
    minimumStack.push_back(inputArray[i]);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll k, n, x, a, b, c; cin >> k >> n >> x >> a >> b >> c;
    inputArray = vl(k); inputArray[0]=x;
    REP(i, 1, k-1) inputArray[i] = (inputArray[i-1]*a + b) % c;


    REP(i, 0, n-1) updateStack(i);
    ll xorMinimum = minimumStack.front();

    REP(i, 0, k-n-1) {
        if (!minimumStack.empty() && minimumStack.front() == inputArray[i]) minimumStack.pop_front();
        updateStack(i+n);
        xorMinimum ^= minimumStack.front();
    }

    cout << xorMinimum;

    return 0;
}

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

void printPairs(ll left, ll right) {
    while (left < right) {
        cout << left << ' ' << right << ' ';
        left+=2, right-=2;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll n; cin >> n;
    if (n*(n+1)/2 & 1) return cout << "NO", 0;
    cout << "YES" << "\n";

    ll left = 1, right = n;
    cout << n/2 << "\n";
    if (n&1) {
        cout << right << ' ';
        right--;
    }

    printPairs(left+1, right-1);
    cout << n/2 + (n&1) << "\n";
    printPairs(left, right);

    return 0;
}
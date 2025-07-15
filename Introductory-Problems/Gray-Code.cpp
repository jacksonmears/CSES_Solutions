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
    ll total = 1 << n;

    for (ll i = 0; i < total; i++) {
        ll gray = i ^ (i >> 1);  // gray code formula
        bitset<16> b(gray);
        cout << b.to_string().substr(16 - n) << endl;
    }



    return 0;
}
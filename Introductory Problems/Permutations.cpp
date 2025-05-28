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
    if (n == 2 || n == 3) return cout << "NO SOLUTION", 0;
    for (ll i = 2; i <= n; i+=2) cout << i << ' ';
    for (ll i = 1; i <= n; i+=2) cout << i << ' ';


    return 0;
}
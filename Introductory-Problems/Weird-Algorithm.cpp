#include <bits/stdc++.h>
#if __has_include("../include/print_ostream.h")
    #include "../include/print_ostream.h"
#endif
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
    cout << n << ' ';

    while (n > 1) {
        n = !(n&1) ? n/2 : n*3 + 1;
        // jack::print(n);
        std::cout << n << " ";
     }


    return 0;
}
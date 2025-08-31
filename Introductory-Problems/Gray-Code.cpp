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
#define rep(i,a,b) for (int i = a; i <= b; ++i)




int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n; cin >> n;
    int total = 1 << n;

    // bitsets are a super powerful tool in C++ that will be used often later on in the CSES problem set!
    rep(i, 0, total-1) {
        int gray = i ^ (i >> 1);          
        bitset<16> b(gray);
        cout << b.to_string().substr(16 - n) << endl;
    }



    return 0;
}
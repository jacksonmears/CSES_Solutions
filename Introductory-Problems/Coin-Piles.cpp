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

    int t; cin >> t;
    rep(i, 0, t-1) {
        int a, b; cin >> a >> b;

        int left = max(a, b), right = min(a, b);
        if (left > right*2) {
            cout << "NO\n";
            continue;
        }


        int difference = left - right;
        left -= difference*2, right -= difference;

        cout << ((!(left%3) && !(right%3) || left%3==2 && right%3 == 1) ? "YES" : "NO") << "\n";

    }


    return 0;
}
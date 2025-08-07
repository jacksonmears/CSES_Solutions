#include <bits/stdc++.h>
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




int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll left = 1, right = 1e9;

    while (left < right) {
        const ll middle = (left + right) / 2;
        cout << "? " << middle << endl << flush;
        string s; cin >> s;
        s == "YES" ? left = middle + 1 : right = middle;
    }

    cout << "! " << left << endl << flush;

    return 0;
}



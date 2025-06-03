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
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)








int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);


    ll n, x; cin >> n >> x;
    vl bookPrice(n); REP(i, 0, n-1) cin >> bookPrice[i];
    vector<pl> setOfBooks;
    REP(i, 0, n-1) {
        ll newPageCount; cin >> newPageCount;
        setOfBooks.emplace_back(bookPrice[i], newPageCount);
    }

    vl dynamicProgramming(x+1, -1); dynamicProgramming[0] = 0; ll mx = 0;
    for (auto book : setOfBooks) {
        for (ll i = x-book.first; i >= 0; i--) {
            if (dynamicProgramming[i] >= 0) {
                dynamicProgramming[i+book.first] = max(dynamicProgramming[i+book.first], dynamicProgramming[i]+book.second);
                mx = max(mx, dynamicProgramming[i+book.first]);
            }
        }
    }

    cout << mx;

    return 0;
}
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

vl factoryMachines;
ll targetProducts;

ll calculateProductCreation(ll middle) {
    ll countProducts = 0;
    for (auto machine : factoryMachines) {
        countProducts += middle/machine;
        if (countProducts >= targetProducts) break;
    }
    return countProducts;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll n; cin >> n >> targetProducts;
    factoryMachines = vl(n); REP(i, 0, n-1) cin >> factoryMachines[i];

    ll left = 0, right = 1e18; ll middle = (right+left)/2;

    while (left < right) {
        ll currentProductsCreated = calculateProductCreation(middle);
        currentProductsCreated >= targetProducts ? right = middle : left = middle+1;
        middle = (right+left)/2;
    }

    cout << middle;



    return 0;
}

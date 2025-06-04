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

    ll n, m, k; cin >> n >> m >> k;
    vl desiredSizes(n), availableSizes(m);
    REP(i, 0, n-1)  cin >> desiredSizes[i];
    REP(i, 0, m-1) cin >> availableSizes[i];

    ranges::sort(desiredSizes);
    ranges::sort(availableSizes);
    ll counter = 0, currentDesiredSize = n-1, currentAvailableSize = m-1;

    while (currentDesiredSize >= 0 && currentAvailableSize >= 0){
        if (abs(availableSizes[currentAvailableSize]-desiredSizes[currentDesiredSize]) <= k){
            counter++;
            currentDesiredSize--;
            currentAvailableSize--;
        }
        else {
            availableSizes[currentAvailableSize] > desiredSizes[currentDesiredSize] ? currentAvailableSize-- : currentDesiredSize--;
        }
    }

    cout << counter << endl;


    return 0;
}
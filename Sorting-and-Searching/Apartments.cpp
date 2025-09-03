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

    int n, m; ll k; 
    cin >> n >> m >> k;
    vl desired(n), available(m);

    REP(i, 0, n-1)  cin >> desired[i];
    REP(i, 0, m-1) cin >> available[i];

    ranges::sort(desired); ranges::sort(available);

    ll counter = 0, cur_desired = n-1, cur_available = m-1;

    while (cur_desired >= 0 && cur_available >= 0){
        if (abs(available[cur_available]-desired[cur_desired]) <= k){
            counter++;
            cur_desired--;
            cur_available--;
        }
        else {
            available[cur_available] > desired[cur_desired] ? cur_available-- : cur_desired--;
        }
    }

    cout << counter << endl;


    return 0;
}
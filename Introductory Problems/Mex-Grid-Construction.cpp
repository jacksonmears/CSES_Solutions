#include <bits/stdc++.h>
#include <regex>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
const int maxOfN = 1e5+1;
constexpr ll MOD = 1e9 + 7;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)






int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll n; cin >> n;
    unordered_map<ll, unordered_set<ll>> rowValues, columnValues;
    REP(row, 0, n-1) {
      REP(column, 0, n-1) {
          ll newValue = 0;
          while (rowValues[row].contains(newValue) || columnValues[column].contains(newValue)) {
              newValue++;
          }
          rowValues[row].insert(newValue), columnValues[column].insert(newValue);
          cout << newValue << " ";
      }
        cout << "\n";
    }

    return 0;
}

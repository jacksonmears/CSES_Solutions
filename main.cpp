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

void printPairs(ll mx, ll mn) {
    while (mn < mx) cout << mn << ' ' << mx << ' ', mx-=2, mn+=2;
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);


    vl nums = {2,7,11,15}; ll target = 9;

    unordered_map<int, int> mp;
    int i = 0;
    while (mp.find(target-nums[i]) == mp.end()) {
        mp[nums[i]] = i, i++;
    }

    cout << "[" << mp[target-nums[i]] << ", " << i << ']' << endl;



    return 0;
}
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


void solve(const ll start, const ll end, const ll holder, const ll len){
    if (len <= 0) return;

    solve(start, holder, end, len-1);
    cout << start << " " << end << endl;
    solve(holder, end, start, len-1);
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll n; cin >> n;
    cout << pow(2,n)-1 << endl;
    solve(1,3,2,n);



    return 0;
}
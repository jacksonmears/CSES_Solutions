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

void dfs(const ll x, const ll y, vector<vl>& v, const ll height, const ll length){
    if (x < 0 || x >= length || y < 0 || y >= height || !v[y][x]) return;

    v[y][x] = 0;
    dfs(x+1, y, v, height, length);
    dfs(x-1, y, v, height, length);
    dfs(x, y+1, v, height, length);
    dfs(x, y-1, v, height, length);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll n,m; cin >> n >> m;
    vector<vl> v(n, vl(m,0));

    REP(i, 0, n-1){
        REP(j, 0, m-1){
            char inp; cin >> inp;
            if (inp == '.') v[i][j] = 1;
        }
    }
    ll count = 0;

    REP(i, 0, n-1){
        REP(j, 0, m-1){
            if (v[i][j] == 1){
                count++;
                dfs(j,i,v,n,m);
            }
        }
    }

    cout << count;


    return 0;
}
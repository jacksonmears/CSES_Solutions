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


ll n, m;

void dfs(const ll row, const ll column, vector<vl>& mapOfBuilding){
    if (column < 0 || column >= m || row < 0 || row >= n || !mapOfBuilding[row][column]) return;

    mapOfBuilding[row][column] = 0;
    dfs(row+1, column, mapOfBuilding);
    dfs(row-1, column, mapOfBuilding);
    dfs(row, column+1, mapOfBuilding);
    dfs(row, column-1, mapOfBuilding);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    vector<vl> mapOfBuilding(n, vl(m,0));

    REP(i, 0, n-1){
        REP(j, 0, m-1){
            char inp; cin >> inp;
            if (inp == '.') mapOfBuilding[i][j] = 1;
        }
    }
    ll count = 0;

    REP(i, 0, n-1){
        REP(j, 0, m-1){
            if (mapOfBuilding[i][j] == 1){
                count++;
                dfs(i,j,mapOfBuilding);
            }
        }
    }

    cout << count;


    return 0;
}
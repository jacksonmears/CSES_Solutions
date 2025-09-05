#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<pl> vpl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
constexpr int MOD = 1e9 + 7;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = a; i >= b; --i)



struct Interval {
    ll left, right, index;
};


constexpr int maxN = 2e5+1, SIZE = 2*maxN;

int n, value_id, ans[2][maxN], fenwick[SIZE];
Interval intervals[maxN];
set<ll> unique_vals;
map<ll,int> m;
ll x, y;

void update(int index, int value){
    for(int i = index; i < SIZE; i += -i&i)   
        fenwick[i] += value;
}

int query(int index){
    int sum = 0;
    for(int i = index; i > 0; i -= -i&i)
        sum += fenwick[i];
    return sum;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);


    cin >> n;
    rep(i, 0, n-1) {
        cin >> x >> y;
        Interval z = {x, y, i};
        intervals[i] = z;
        unique_vals.insert(x);
        unique_vals.insert(y);
    }

    sort(intervals, intervals+n, [](Interval a, Interval b){
        if (a.left == b.left) return a.right > b.right;
        return a.left < b.left;
    });

    for(int x : unique_vals)
        m[x] = ++value_id;

    repr(i, n-1, 0) {
        int y = m[intervals[i].right];
        int id = intervals[i].index;
        ans[0][id] = query(y);
        update(y, 1);
    }

    fill(fenwick, fenwick+SIZE, 0);
    rep(i, 0, n-1) {
        int y = m[intervals[i].right];
        int id = intervals[i].index;
        ans[1][id] = i-query(y-1);
        update(y, 1);
    }


    rep(i, 0, n-1) cout << (ans[0][i] ? 1 : 0) << " ";
    cout << "\n";
    rep(i, 0, n-1) cout << (ans[1][i] ? 1 : 0) << " ";


    return 0;
}
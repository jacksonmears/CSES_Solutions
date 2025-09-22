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
typedef vector<char> vc;
constexpr int MOD = 1e9 + 7;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = a; i >= b; --i)
 

struct Query {
    int left, right, query_index;
};


constexpr int MAXN = 2e5+1;
int n, q, a, b, elements[MAXN];
vector<Query> queries;
map<ll, int> seen;
vi fenwick;


void update(int i, int value) {
    for (; i <= n; i += i&-i) {
        fenwick[i] += value;
    }
}


int query(int i) {
    int count = 0;
    for (;i > 0; i -= i&-i) {
        count += fenwick[i];
    }
    return count;
}


bool cmp(Query& a, Query& b) {
    if (a.right == b.right) return a.left < b.left;
    return a.right < b.right;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);


    cin >> n >> q;
    rep(i, 1, n) cin >> elements[i];
    vi answer(q, 0);

    fenwick.assign(n+1, 0);

    queries.assign(q, {});
    rep(i, 0, q-1) {
        cin >> queries[i].left >> queries[i].right;
        queries[i].query_index = i;
    }

    sort(queries.begin(), queries.end(), cmp);



    int i = 1;
    for (auto& [left, right, query_index] : queries) {
        while (i <= right) {
            if (seen.find(elements[i]) != seen.end()) {
                update(seen[elements[i]], -1);
            }
            seen[elements[i]] = i;
            update(i, 1);
            ++i;
        }
        answer[query_index] = query(right) - query(left-1);
    }
    

    rep(i, 0, q-1) cout << answer[i] << "\n";



    return 0;
}


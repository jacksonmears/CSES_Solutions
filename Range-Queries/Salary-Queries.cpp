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
 

int n, q, a, b, vals_size;
string type;
vi fenwick, vals;

struct Query {
    string type_query;
    int a, b;
};

void update(int index, int value) {
    for (int i = index+1; i <= vals_size; i += i&-i) 
        fenwick[i] += value;
}

int query(int index) {
    int sum = 0;
    for (int i = index+1; i > 0; i -= i&-i) 
        sum += fenwick[i];
    return sum;
}

int rangeQuery(int left, int right) {
    return query(right) - (left ? query(left-1) : 0);
}


int fetch_compressed_value(int x) {
    return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin());
}

 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    cin >> n >> q;

    vi salary(n);
    vector<Query> queries(q);
 
    rep(i, 0, n-1) {
        cin >> salary[i];
        vals.pb(salary[i]);
    }
 
    rep(i, 0, q-1) {
        cin >> type;
        if (type == "!") {
            cin >> a >> b;
            --a;
            queries[i] = {type, a, b};
            vals.pb(b);
        } else {
            cin >> a >> b;
            queries[i] = {type, a, b};
            vals.pb(a);
            vals.pb(b);
        }
    }
 
    ranges::sort(vals);
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
 
    vals_size = vals.size();
    fenwick.assign(vals_size+1, 0);
 
    rep(i, 0, n-1) 
        update(fetch_compressed_value(salary[i]), 1);
    
 
    for (auto &query : queries) {
        if (query.type_query == "!") {
            update(fetch_compressed_value(salary[query.a]), -1);
            salary[query.a] = query.b;
            update(fetch_compressed_value(query.b), 1);
 
        } else { 
            int left = fetch_compressed_value(query.a);
            int right = fetch_compressed_value(query.b);
 
            cout << rangeQuery(left, right) << "\n";
        }
    }
    return 0;
}
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


int n;
ll x, a, need;

struct Element {
    ll value;
    int index;
};
vector<Element> elements;

bool compare(Element& a, Element&b) {
    if (a.value == b.value) return a.index < b.index;
    return a.value < b.value;
}

bool cmpLowerBound(const Element& e, ll val) {
    return e.value < val; 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> x;
    elements.assign(n, {});
    rep(i, 0, n-1) {
        cin >> a;
        elements[i] = {a, i+1};
    }

    sort(elements.begin(), elements.end(), compare);

    rep(i, 0, n-1) {
        if (i > i+1 && elements[i].value == elements[i-1].value) 
            continue;

        rep(j, i+1, n-1) {
            need = x - elements[i].value - elements[j].value;
            auto it = lower_bound(elements.begin()+j+1, elements.end(), need, cmpLowerBound);

            if (it->index <= n && it->value == need) {
                cout << elements[i].index << " " << elements[j].index << " " << it->index;
                return 0;
            }
        }
    }


    cout << "IMPOSSIBLE";

    return 0;
}

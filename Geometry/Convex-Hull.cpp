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

struct Node {
    long long x, y;
};


bool cmp(Node& a, Node& b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}


// cross product (b - a) × (c - a)
long long cross(const Node& a, const Node& b, const Node& c) {
    return (b.x - a.x) * (c.y - a.y) - 
           (b.y - a.y) * (c.x - a.x);
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    vector<Node> nodes(n);
    rep(i, 0, n-1)
        cin >> nodes[i].x >> nodes[i].y;

    sort(nodes.begin(), nodes.end(), cmp);

    vector<Node> hull;

    // Build lower hull
    for (auto& node : nodes) {
        while (hull.size() >= 2 && cross(hull[hull.size()-2], hull.back(), node) < 0)
            hull.pop_back();
        hull.pb(node);
    }

    // Build upper hull
    size_t lower_size = hull.size();
    for (int i = (int)nodes.size() - 2; i >= 0; i--) {
        Node node = nodes[i];
        while (hull.size() > lower_size && cross(hull[hull.size()-2], hull.back(), node) < 0)
            hull.pop_back();
        hull.pb(node);
    }

    hull.pop_back();

    cout << hull.size() << "\n";
    for (auto& node : hull) {
        cout << node.x << " " << node.y << "\n";
    }
    return 0;
}
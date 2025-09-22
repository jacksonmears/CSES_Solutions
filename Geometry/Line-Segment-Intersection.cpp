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
 
int t;
ll X1, Y1, X2, Y2, X3, Y3, X4, Y4;

ll cross(ll x1, ll y1, ll x2, ll y2) {
    return x1 * y2 - y1 * x2;
}
ll orient(ll ax, ll ay, ll bx, ll by, ll cx, ll cy) {
    return cross(bx - ax, by - ay, cx - ax, cy - ay);
}
bool between(ll a, ll b, ll p) {
    return min(a, b) <= p && p <= max(a, b);
}
bool on_segment(ll ax, ll ay, ll bx, ll by, ll cx, ll cy) {
    return between(ax, bx, cx) && between(ay, by, cy);
}

bool segments_intersect() {
    ll o1 = orient(X1, Y1, X2, Y2, X3, Y3);
    ll o2 = orient(X1, Y1, X2, Y2, X4, Y4);
    ll o3 = orient(X3, Y3, X4, Y4, X1, Y1);
    ll o4 = orient(X3, Y3, X4, Y4, X2, Y2);

    // general case: strictly opposite signs (no zeros)
    bool general = ((o1 > 0 && o2 < 0) || (o1 < 0 && o2 > 0)) &&
                   ((o3 > 0 && o4 < 0) || (o3 < 0 && o4 > 0));
    if (general) return true;

    // special (collinear) cases: check if a point lies on the other segment
    if (o1 == 0 && on_segment(X1, Y1, X2, Y2, X3, Y3)) return true;
    if (o2 == 0 && on_segment(X1, Y1, X2, Y2, X4, Y4)) return true;
    if (o3 == 0 && on_segment(X3, Y3, X4, Y4, X1, Y1)) return true;
    if (o4 == 0 && on_segment(X3, Y3, X4, Y4, X2, Y2)) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3 >> X4 >> Y4;
        cout << (segments_intersect() ? "YES\n" : "NO\n");
    }
    
    return 0;
}

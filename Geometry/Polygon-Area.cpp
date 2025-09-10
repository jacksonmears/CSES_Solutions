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
 

struct Point {
    ll x, y;
};


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    int n; cin >> n;
    ll x1, x2, y1, y2;
    vector<Point> points(n);
    rep(i, 0, n-1) 
        cin >> points[i].x >> points[i].y;
    
    ll area = 0;
    rep(i, 0, n-1) {
        x1 = points[i].x;
        y1 = points[i].y;

        x2 = points[(i + 1) % n].x;
        y2 = points[(i + 1) % n].y;

        area += ((x1 * y2) - (x2 * y1));
    }
    

    cout << abs(area);

    return 0;
}

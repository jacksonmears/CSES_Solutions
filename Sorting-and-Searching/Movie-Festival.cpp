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
ll a, b;

struct Movie {
    ll start, end;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n; 
    vector<Movie> movies(n);
    rep(i, 0, n-1) {
        cin >> a >> b;
        Movie x = {a, b};
        movies[i] = x;
    }

    ranges::sort(movies, [](Movie m1, Movie m2) {
        if (m1.end != m2.end) return m1.end < m2.end;
        return m1.start < m2.start;
    });

    auto it = movies.begin();
    ll prev = 0, counter = 0;
    while (it != movies.end()) {
        if (it->start >= prev) {
            ++counter;
            prev = it->end;
        }
        ++it;
    }

    cout << counter;

    return 0;
}

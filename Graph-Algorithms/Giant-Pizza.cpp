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
 

constexpr int MAXN = 1e5+1;
int n, m, x, y;
char wantA, wantB;
int good[MAXN], bad[MAXN];
char answer[MAXN];

struct Wish {
    int a, b;
    int mxAffected, mnAffected;
}; 

Wish wishes[MAXN];


int sign(char want) {
    return (want == '+') ? 1 : -1;
}


void populateMinMaxAffected(Wish& w) {
    int affectedA = (w.a > 0) ? bad[w.a] : good[w.a*-1];
    int affectedB = (w.b > 0) ? bad[w.b] : good[w.b*-1];
    if (affectedA > affectedB) swap(w.a, w.b);
    w.mxAffected = max(affectedA, affectedB);
    w.mnAffected = min(affectedA, affectedB);
}

bool comparitor(const Wish& a, const Wish& b) {
    if (a.mnAffected == b.mnAffected) return a.mxAffected < b.mxAffected;
    return a.mnAffected < b.mnAffected;
}


bool checkAnswerSign(const int& value) {
    return ((value > 0 && answer[abs(value)] == '+') || (value < 0 && answer[abs(value)] == '-'));
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    
    cin >> n >> m;
    rep(i, 0, n-1) {
        cin >> wantA >> x >> wantB >> y;
        wishes[i].a = sign(wantA)*x, wishes[i].b = sign(wantB)*y;
        (wishes[i].a > 0) ? ++good[wishes[i].a] : ++bad[wishes[i].a*-1];
        (wishes[i].b > 0) ? ++good[wishes[i].b] : ++bad[wishes[i].b*-1];
    }

    rep(i, 0, n-1)
        populateMinMaxAffected(wishes[i]);

    
    sort(wishes, wishes + n, comparitor);

    
    rep(i, 0, n-1) {
        Wish* w = &wishes[i];
        if (!answer[abs(w->a)] || checkAnswerSign(w->a)) 
            answer[abs(w->a)] = (w->a > 0) ? '+' : '-';
        
        else if (!answer[abs(w->b)] || checkAnswerSign(w->b)) 
            answer[abs(w->b)] = (w->b > 0) ? '+' : '-';
        
        else return cout << "IMPOSSIBLE", 0;
    }

    rep(i, 1, m) 
        cout << ((answer[i]) ? answer[i] : '+') << " ";


    return 0;
}


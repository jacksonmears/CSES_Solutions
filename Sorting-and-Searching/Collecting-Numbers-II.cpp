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


constexpr int MAXN = 2e5+1;
int n, m, a, b, counter = 1;
int elements[MAXN], pos[MAXN];


void update(int a, int b){
    if(pos[elements[a]-1] <= pos[elements[a]] && b < pos[elements[a]-1]) ++counter;
    if(pos[elements[a]-1] > pos[elements[a]] && b >= pos[elements[a]-1]) --counter;
    if(pos[elements[a]+1] >= pos[elements[a]] && b > pos[elements[a]+1]) ++counter;
    if(pos[elements[a]+1] < pos[elements[a]] && b <= pos[elements[a]+1]) --counter;
    pos[elements[a]] = b;

    if(pos[elements[b]-1] <= pos[elements[b]] && a < pos[elements[b]-1]) ++counter;
    if(pos[elements[b]-1] > pos[elements[b]] && a >= pos[elements[b]-1]) --counter;
    if(pos[elements[b]+1] >= pos[elements[b]] && a > pos[elements[b]+1]) ++counter;
    if(pos[elements[b]+1] < pos[elements[b]] && a <= pos[elements[b]+1]) --counter;
    pos[elements[b]] = a;

    swap(elements[a], elements[b]);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    rep(i, 1, n) {
        cin >> elements[i];
        pos[elements[i]] = i;
    }

    rep(i, 2, n) 
        if (pos[i] < pos[i - 1]) 
            ++counter;


    rep(i, 0, m-1) {
        cin >> a >> b;
        update(a, b);
        cout << counter << "\n";
    }


    return 0;
}

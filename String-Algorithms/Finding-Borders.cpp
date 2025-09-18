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
 


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    string s; cin >> s;

    vi kmp(s.size());
    vi borders; borders.reserve(s.size()+1);

    for (int i = 1; i < (int)s.size(); ++i) {
        int j = kmp[i-1];
        while (j > 0 && s[i] != s[j]) j = kmp[j-1];
        if (s[i] == s[j]) ++j;
        kmp[i] = j;
    }

 
    int right = s.size()-1;
    while (right > 0 && kmp[right]) {
        borders.pb(kmp[right]);
        right = kmp[right]-1;
    }

    repr(i, borders.size()-1, 0) cout << borders[i] << " ";
    

    return 0;
}


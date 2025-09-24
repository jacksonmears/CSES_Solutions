#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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



constexpr int N = 3005;
int n;
string s;
bitset<N> bsets[N];
ll cnt = 0, t;
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    rep(i, 0, n-1) {
        cin >> s;
        rep(j, 0, n-1)
            bsets[i][j] = s[j] == '1';
    }

    rep(i, 1, n-1) {
        rep(j, 0, i-1) {
            t = (bsets[i]&bsets[j]).count();
            cnt += t*(t-1)/2;
        }
 
    }
    cout << cnt << endl;
}
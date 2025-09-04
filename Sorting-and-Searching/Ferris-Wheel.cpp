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
ll x;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> x; 
    vl listOfWeights(n);
    rep(i, 0, n-1) 
        cin >> listOfWeights[i];

    ranges::sort(listOfWeights);

    int left = 0, right = n-1, counter = 0;
    while (left <= right) {
        if (listOfWeights[left] + listOfWeights[right] <= x) left++;
        right--; counter++;
    }

    cout << counter << endl;

    return 0;
}
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
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define repr(i, a, b) for (int i = a; i >= b; i--)


int alphabet[26];


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    string s; cin >> s;
    int n = s.size();

    for (char c : s) alphabet[c - 'A']++;

    int odd_count = 0, odd_char = -1;
    rep(i, 0, 25) {
        if (alphabet[i]&1) {
            odd_count++;
            odd_char = i;
        }
    }
    if (odd_count > 1) 
        return cout << "NO SOLUTION\n", 0; 
    

    string answer(n, ' '); 
    int left = 0, right = n-1;

    rep(i, 0, 25) {
        while (alphabet[i] >= 2) {
            answer[left++] = char(i + 'A');
            answer[right--] = char(i + 'A');
            alphabet[i] -= 2;
        }
    }

    if (odd_count == 1) answer[left] = char(odd_char + 'A');

    cout << answer << "\n";

    
    return 0;
}


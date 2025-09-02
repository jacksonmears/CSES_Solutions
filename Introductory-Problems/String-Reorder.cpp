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

string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);


    cin>>s; 
    int n = s.size();
    ranges::sort(s);
    set<int> string_set;

    int container[27] = {0};

    for (const char c: s) {
        container[c-'A']++; string_set.insert(c);
    }

    auto iter = max_element(container, container+27);
    if (2**iter - n > 1) return cout << -1, 0;

    string ans;
    char prev = 26+'A';

    while(2**iter - n < 1) {
        char current = *string_set.begin();
        string_set.erase(current);
        ans += current; container[current-'A']--;
        if (container[prev-'A'])
            string_set.insert(prev);
        prev = current;
        iter = max_element(container, container+27);
        n--;
    }

    // if there's too many of one letter remaining (7 letters left and 4 T's still need to be used)
    if (*iter) {
        string string_catch; char current = iter-container+'A';              //char causing issues (equal to or more than the rest of char combined)
        rep(i, 0, 25) if (current-'A' != i)                                 //for loop goes through each char in container and adds however many are left (if there are 3 A's then stringCatch will be "...AAA"
            rep(j, 0, container[i]-1)
                string_catch += i+'A';
        for (auto i: string_catch)                                       //goes through each char in stringCatch and adds the problem char + a caught char to ans to prevent them problem char from being adjacent
            ans += current, ans += i;
        ans += current;                                                     //cleaning up last current char
    //
    }
    cout<<ans;



    return 0;
}
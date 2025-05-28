#include <bits/stdc++.h>
#include <regex>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
constexpr ll MAX = 9e18;
constexpr ll MOD = 1e9 + 7;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);


    string s; cin>>s; ll n = s.size();
    ranges::sort(s);
    set<ll> stringSet;
    int container[27] = {0};
    for (const char c: s) {
        container[c-'A']++; stringSet.insert(c);
    }

    auto iter = max_element(container, container+27);
    if (2**iter - n > 1) return cout << -1, 0;

    string ans;
    char prev = 26+'A';

    while(2**iter - n < 1) {
        char current = *stringSet.begin();
        stringSet.erase(current);
        ans += current; container[current-'A']--;
        if (container[prev-'A'])
            stringSet.insert(prev);
        prev = current;
        iter = max_element(container, container+27);
        n--;
    }

    // if there's too many of one letter remaining (7 letters left and 4 T's still need to be used)
    if (*iter) {
        string stringCatch; char current = iter-container+'A';              //char causing issues (equal to or more than the rest of char combined)
        REP(i, 0, 25) if (current-'A' != i)                                 //for loop goes through each char in container and adds however many are left (if there are 3 A's then stringCatch will be "...AAA"
            REP(j, 0, container[i]-1)
                stringCatch += i+'A';
        for (auto i: stringCatch)                                       //goes through each char in stringCatch and adds the problem char + a caught char to ans to prevent them problem char from being adjacent
            ans += current, ans += i;
        ans += current;                                                     //cleaning up last current char
    //
    }
    cout<<ans;



    return 0;
}
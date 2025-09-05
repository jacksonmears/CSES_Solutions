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
 
constexpr int MAXN = 2e5-1;
int n, counter = 0, ans[MAXN];
 
 
struct Customer {
    ll arrive, leave, index;
};
 
 
bool cmp(const Customer& a, const Customer& b) {
    if (a.arrive == b.arrive) return a.leave < b.leave;
    return a.arrive < b.arrive; 
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    cin >> n;
 
    vector<Customer> customers(n);
    multiset<pi> rooms;
    rep(i, 0, n-1) {
        cin >> customers[i].arrive >> customers[i].leave;
        customers[i].index = i;
    }
    
    sort(customers.begin(), customers.end(), cmp);
    rep(i, 0, n-1) {
        if (rooms.empty() || rooms.begin()->f >= customers[i].arrive){
            ++counter;
            rooms.insert({customers[i].leave, counter});
            ans[customers[i].index] = counter;
        }
        else{
            rooms.insert({customers[i].leave, rooms.begin()->s});
            ans[customers[i].index] = rooms.begin()->s;
            rooms.erase(rooms.begin());
        }
    }
 
    cout << counter << "\n";
    rep(i, 0, n-1) cout << ans[i] << " ";
    
    
    return 0;
}

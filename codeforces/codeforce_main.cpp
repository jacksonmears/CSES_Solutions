#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    // Check if all equal
    bool all_equal = true;
    for (int i = 1; i < n; i++)
        if (a[i] != a[0]) all_equal = false;
    if (all_equal) {
        cout << 0 << "\n";
        return;
    }

    int ans = 0;
    vector<int> extended = a;
    extended.push_back(a[0]); // to handle circular wrap easily

    int len = 1;
    for (int i = 1; i <= n; i++) {
        if (extended[i] != extended[i-1]) {
            len++;
        } else {
            if (len > 1) ans += len / 2;
            len = 1;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}

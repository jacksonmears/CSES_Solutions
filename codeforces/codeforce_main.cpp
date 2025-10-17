#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(const vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n / 2; ++i)
        if (a[i] != a[n - 1 - i])
            return false;
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    if (!is_palindrome(a)) {
        for (int i = 0; i < k; ++i) cout << a[0] << " ";
        cout << "\n";
        return;
    }

    int x = 1;
    while (x == a[0]) x++;
    for (int i = 0; i < k; ++i) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}

#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

// Queries the original permutation p[l..r]
long long query_p(long long l, long long r) {
    cout << "1 " << l << " " << r << endl;
    cout.flush();
    long long x; cin >> x;
    return x;
}

// Queries the modified array a[l..r]
long long query_a(long long l, long long r) {
    cout << "2 " << l << " " << r << endl;
    cout.flush();
    long long x; cin >> x;
    return x;
}

// Output the final answer
void answer(long long L, long long R) {
    cout << "! " << L << " " << R << endl;
    cout.flush();
}

void solve() {
    long long n;
    cin >> n;

    long long total_p = query_p(1, n);
    long long total_a = query_a(1, n);
    long long diff = total_a - total_p;  // R - L + 1

    long long lo = 1, hi = n, L = -1;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        long long sum_p = query_p(1, mid);
        long long sum_a = query_a(1, mid);
        if (sum_a - sum_p > 0) {
            L = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    lo = L; hi = n;
    long long R = -1;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        long long sum_p = query_p(1, mid);
        long long sum_a = query_a(1, mid);
        if (sum_a - sum_p < diff) {
            lo = mid + 1;
        } else {
            R = mid;
            hi = mid - 1;
        }
    }

    answer(L, R);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}

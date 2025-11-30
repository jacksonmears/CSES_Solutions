#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#if __has_include("../include/print_ostream.h")
    #include "../include/print_ostream.h"
#endif
using namespace std;

using ll = long long;
using d = double;
using ld = long double;

using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vd = vector<d>;
using vld = vector<ld>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using pldld = pair<ld, ld>;
using vpii = vector<pii>;
using vvl = vector<vl>;
using vpl = vector<pll>;
using vb = vector<bool>;
using vc = vector<char>;

#define pb push_back
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define repr(i,a,b) for (int i = a; i >= b; --i)

constexpr uint32_t MOD = 1e9 + 7;
constexpr ll INF = 9e18;
constexpr ll NEG_INF = -9e18;


#define LEFT_STACK 0
#define RIGHT_STACK 1


void fill_data(vi* v, vi* d, int n, int flag) {
    stack<int> st;
    int default_val = (!flag*-1)+(flag*n); 

    for (
        int i = (n-1)*flag; 
        i >= 0 && i < n; 
        i += (!flag)+(flag*-1)
    ) 
    {
        while (!st.empty() && (*v)[st.top()] >= (*v)[i]) st.pop();
        (*d)[i] = st.empty() ? default_val : st.top();
        st.push(i);
    }
}



class Line {
private:
    ll m, b; // slope and intercept 

public:
    Line(ll _m = 0, ll _b = NEG_INF) : m(_m), b(_b) {}

    ll eval(int x) const { 
        return m*(ll)x + b; 
    }

};




struct Node { 
    Line ln; 
    int l=-1, r=-1; 
};





class LiChao {
private:
    int n;
    vector<Node> seg;
    int root;

    int new_node(Line ln) { 
        seg.emplace_back(ln); 
        return (int)seg.size()-1; 
    }

    void add_segment_internal(int idx, int L, int R, int l, int r, Line ln) {
        if (r < L || R < l) return;
        if (l <= L && R <= r) {
            int mid = (L+R)>>1;
            Line low = seg[idx].ln, high = ln;
            if (low.eval(L) < high.eval(L)) swap(low, high);
            if (low.eval(R) >= high.eval(R)) { seg[idx].ln = low; return; }
            if (low.eval(mid) >= high.eval(mid)) {
                seg[idx].ln = low;
                if (seg[idx].r == -1) seg[idx].r = new_node(Line{});
                add_segment_internal(seg[idx].r, mid+1, R, l, r, high);
            } else {
                seg[idx].ln = high;
                if (seg[idx].l == -1) seg[idx].l = new_node(Line());
                add_segment_internal(seg[idx].l, L, mid, l, r, low);
            }
            return;
        }
        int mid = (L+R)>>1;
        if (seg[idx].l == -1) seg[idx].l = new_node(Line{});
        if (seg[idx].r == -1) seg[idx].r = new_node(Line{});
        add_segment_internal(seg[idx].l, L, mid, l, r, ln);
        add_segment_internal(seg[idx].r, mid+1, R, l, r, ln);
    }



    ll query_internal(int idx, int L, int R, int x) const {
        if (idx == -1) return NEG_INF;
        ll res = seg[idx].ln.eval(x);
        if (L == R) return res;
        int mid = (L+R)>>1;
        if (x <= mid) {
            if (seg[idx].l == -1) return res;
            return max(res, query_internal(seg[idx].l, L, mid, x));
        } else {
            if (seg[idx].r == -1) return res;
            return max(res, query_internal(seg[idx].r, mid+1, R, x));
        }
    }
public:
    LiChao(int _n=0): n(_n) {
        seg.reserve(max(4,4*n+50));
        seg.emplace_back(Line{});
        root = 0;
    }

    void add_segment(int l, int r, Line ln) {
        if (l > r || n <= 0) return;
        add_segment_internal(root, 0, n-1, l, r, ln);
    }

    ll query(int x) const {
        if (n <= 0) return 0;
        ll ans = query_internal(root, 0, n-1, x);
        if (ans == NEG_INF) return 0;
        return ans;
    }
};











int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, k; cin >> n >> k;

    vi v(n), L(n), R(n);
    rep(i, 0, n-1) cin >> v[i];

    // monotonic stack for first values (v[i]) left and right of i stored in L[i] and R[i]
    fill_data(&v, &L, n, LEFT_STACK);
    fill_data(&v, &R, n, RIGHT_STACK);

    // no need to search past this point (no more valid windows)
    int m = n - k + 1; 

    // instantiate lichao 
    LiChao lichao {m};

    rep(i, 0, n-1) { 
        ll current_height = v[i];                               // Height of the current index

        int left_min_index      =   L[i] + 1;                   // Leftmost index where height v[i] is the minimum;
        int right_min_index     =   R[i] - 1;                   // Rightmost index where height v[i] is the minimum; 
        int Wlow                =   left_min_index - k + 1;    // Earliest possible inclusion in a window
        int left_window_index   =   max(0, Wlow);               // clamp earliest/latest to valid indicies


        // board will be referred to the range where current_height is the min value
        // window partially covers the board from the left side but will add more when window slides to the right
        int start_of_left_partial_overlap   = left_window_index;                                                            // the first index where the baord will increase in area (about to enter the window)
        int end_of_left_partial_overlap     = min(left_min_index-1, right_min_index - k + 1);                               // the last index where the board will increase in area

        if (start_of_left_partial_overlap <= end_of_left_partial_overlap) { 
            ll line_slope       = current_height;                                                                     // area grows by h as window moves right (length increases)
            ll line_intercept   = current_height * (k - left_min_index);                                          // Intercept: initial area at window start 
            lichao.add_segment(start_of_left_partial_overlap, end_of_left_partial_overlap, Line{line_slope, line_intercept});       // Add line to Li Chao tree for this segment
        }


        // window fully covers board AND board is SMALLER than window in size/length
        if (left_min_index + k > right_min_index) {
            ll constant_area = current_height * (right_min_index - left_min_index + 1);                      // Constant area: full segment covered but less than k
            lichao.add_segment(right_min_index-k+2, left_min_index-1, Line{0, constant_area});               // Add horizontal line to Li Chao tree
        }

        // --- Middle-constant interval ---
        // This interval represents all windows of length k that fully cover the board at index i.
        // The area is constant because the entire board of height 'current_height' is fully inside the window.

        int full_window_start = max(left_window_index, left_min_index);                             // Earliest window start that fully covers this board
        int full_window_end   = min(right_min_index, right_min_index - k + 1);                      // Latest window start for full coverage

        if (full_window_start <= full_window_end) {                                                 // Only add if there exists a starting window index that captures the entire board
            ll constant_area = current_height * k;                                                  // Area = height * window length
            lichao.add_segment(full_window_start, full_window_end, Line{0, constant_area});         // Horizontal line for this interval
        }


        // same concept as the first segment but reversed. Window partially covers board but on the right side so as it moves away the area of the board will decrease.
        int start_of_right_partial_overlap  = max(left_min_index, right_min_index - k + 2);                     // the first index where the board will decrease in area
        int end_of_right_partial_overlap    = right_min_index;                                                  // the last index where the board will decrease in area (about to leave the window)

        if (start_of_right_partial_overlap <= right_min_index) {
            ll line_slope       = -current_height; 
            ll line_intercept   = current_height * (end_of_right_partial_overlap + 1); 
            lichao.add_segment(start_of_right_partial_overlap, end_of_right_partial_overlap, Line{line_slope, line_intercept});
        }
    }



    rep(w, 0, m-1) {
        if (w) cout << ' ';
        cout << lichao.query(w);
    }

    return 0;
}

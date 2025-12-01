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
 
 
 
 
 /**
 * Li Chao Segment Tree (for maximum queries)
 *
 * Supports:
 *   - Adding a line y = m*x + b across a segment [l, r]
 *   - Querying maximum value at x
 *
 * This version uses explicit descriptive names and detailed documentation.
 */

class LiChao {
private:

    /**
     * Represents a linear function y = slope * x + intercept.
     * Default line returns NEG_INF for all x.
     */
    struct Line {
        long long slope;
        long long intercept;

        Line(long long m = 0, long long b = NEG_INF)
            : slope(m), intercept(b) {}

        inline long long evaluate(int x) const {
            return slope * (long long)x + intercept;
        }
    };

    /**
     * Node of the Li Chao segment tree.
     * Each node contains:
     *   - A line that is the current best for this segment
     *   - Indices of left and right children
     */
    struct TreeNode {
        Line storedLine;
        int leftChild = -1;
        int rightChild = -1;
    };

private:
    int domainSize;             // Number of x-values the tree spans (0 to domainSize-1)
    int rootIndex;              // Index of the root node
    vector<TreeNode> tree;      // Dynamic array of nodes

private:

    /**
     * Allocates a new tree node initialized with the provided line.
     */
    int createNode(const Line& line) {
        tree.emplace_back(TreeNode{line});
        return tree.size() - 1;
    }

    /**
     * Internal recursive function to add a line over an interval.
     *
     * Parameters:
     *   nodeIndex – current node in the segment tree
     *   leftBound, rightBound – segment covered by this node
     *   queryLeft, queryRight – the interval where the new line applies
     *   newLine – the line to insert
     */
    void addLineSegmentRecursive(
        int nodeIndex,
        int leftBound, int rightBound,
        int queryLeft, int queryRight,
        Line newLine
    ) {
        // No overlap
        if (queryRight < leftBound || rightBound < queryLeft) {
            return;
        }

        // Full cover: we attempt to insert into this node
        if (queryLeft <= leftBound && rightBound <= queryRight) {

            int mid = (leftBound + rightBound) >> 1;

            Line lowLine = tree[nodeIndex].storedLine;
            Line highLine = newLine;

            // Ensure lowLine(x) >= highLine(x) at leftBound
            if (lowLine.evaluate(leftBound) < highLine.evaluate(leftBound))
                swap(lowLine, highLine);

            // If lowLine is better everywhere on this interval, keep it
            if (lowLine.evaluate(rightBound) >= highLine.evaluate(rightBound)) {
                tree[nodeIndex].storedLine = lowLine;
                return;
            }

            // They cross inside the interval
            if (lowLine.evaluate(mid) >= highLine.evaluate(mid)) {
                // lowLine is better on left half
                tree[nodeIndex].storedLine = lowLine;

                if (tree[nodeIndex].rightChild == -1)
                    tree[nodeIndex].rightChild = createNode(Line());

                addLineSegmentRecursive(
                    tree[nodeIndex].rightChild,
                    mid + 1, rightBound,
                    queryLeft, queryRight,
                    highLine
                );
            } else {
                // highLine is better on left half
                tree[nodeIndex].storedLine = highLine;

                if (tree[nodeIndex].leftChild == -1)
                    tree[nodeIndex].leftChild = createNode(Line());

                addLineSegmentRecursive(
                    tree[nodeIndex].leftChild,
                    leftBound, mid,
                    queryLeft, queryRight,
                    lowLine
                );
            }

            return;
        }

        // Partial coverage → push down both sides
        int mid = (leftBound + rightBound) >> 1;

        if (tree[nodeIndex].leftChild == -1)
            tree[nodeIndex].leftChild = createNode(Line());

        if (tree[nodeIndex].rightChild == -1)
            tree[nodeIndex].rightChild = createNode(Line());

        addLineSegmentRecursive(
            tree[nodeIndex].leftChild,
            leftBound, mid,
            queryLeft, queryRight,
            newLine
        );

        addLineSegmentRecursive(
            tree[nodeIndex].rightChild,
            mid + 1, rightBound,
            queryLeft, queryRight,
            newLine
        );
    }

    /**
     * Internal recursive max query.
     *
     * Returns the maximum y-value reachable at x among all stored lines.
     */
    long long queryRecursive(int nodeIndex, int leftBound, int rightBound, int x) const {
        if (nodeIndex == -1)
            return NEG_INF;

        long long bestValue = tree[nodeIndex].storedLine.evaluate(x);

        if (leftBound == rightBound)
            return bestValue;

        int mid = (leftBound + rightBound) >> 1;

        if (x <= mid) {
            if (tree[nodeIndex].leftChild == -1)
                return bestValue;
            return max(bestValue, queryRecursive(tree[nodeIndex].leftChild, leftBound, mid, x));
        } else {
            if (tree[nodeIndex].rightChild == -1)
                return bestValue;
            return max(bestValue, queryRecursive(tree[nodeIndex].rightChild, mid + 1, rightBound, x));
        }
    }

public:

    /**
     * Constructor.
     *
     * domainSize: number of X positions, valid x ∈ [0, domainSize - 1]
     */
    LiChao(int domainSize = 0) : domainSize(domainSize) {
        tree.reserve(max(4, 4 * domainSize + 50));
        tree.emplace_back(TreeNode{});  // root node with default line
        rootIndex = 0;
    }

    /**
     * Adds a line y = m*x + b over interval [l, r].
     */
    void addLineSegment(int l, int r, const Line& line) {
        if (l > r || domainSize <= 0) return;
        addLineSegmentRecursive(rootIndex, 0, domainSize - 1, l, r, line);
    }

    /**
     * Queries the maximum value at the single point x.
     *
     * Returns 0 if no line covers x (instead of -inf for convenience).
     */
    long long query(int x) const {
        if (domainSize <= 0) return 0;
        long long result = queryRecursive(rootIndex, 0, domainSize - 1, x);
        return (result == NEG_INF ? 0 : result);
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
            lichao.addLineSegment(start_of_left_partial_overlap, end_of_left_partial_overlap, {line_slope, line_intercept});       // Add line to Li Chao tree for this segment
        }
 
 
        // window fully covers board AND board is SMALLER than window in size/length
        if (left_min_index + k > right_min_index) {
            ll constant_area = current_height * (right_min_index - left_min_index + 1);                      // Constant area: full segment covered but less than k
            lichao.addLineSegment(right_min_index-k+2, left_min_index-1, {0, constant_area});               // Add horizontal line to Li Chao tree
        }
 
        // --- Middle-constant interval ---
        // This interval represents all windows of length k that fully cover the board at index i.
        // The area is constant because the entire board of height 'current_height' is fully inside the window.
 
        int full_window_start = max(left_window_index, left_min_index);                             // Earliest window start that fully covers this board
        int full_window_end   = min(right_min_index, right_min_index - k + 1);                      // Latest window start for full coverage
 
        if (full_window_start <= full_window_end) {                                                 // Only add if there exists a starting window index that captures the entire board
            ll constant_area = current_height * k;                                                  // Area = height * window length
            lichao.addLineSegment(full_window_start, full_window_end, {0, constant_area});         // Horizontal line for this interval
        }
 
 
        // same concept as the first segment but reversed. Window partially covers board but on the right side so as it moves away the area of the board will decrease.
        int start_of_right_partial_overlap  = max(left_min_index, right_min_index - k + 2);                     // the first index where the board will decrease in area
        int end_of_right_partial_overlap    = right_min_index;                                                  // the last index where the board will decrease in area (about to leave the window)
 
        if (start_of_right_partial_overlap <= right_min_index) {
            ll line_slope       = -current_height; 
            ll line_intercept   = current_height * (end_of_right_partial_overlap + 1); 
            lichao.addLineSegment(start_of_right_partial_overlap, end_of_right_partial_overlap, {line_slope, line_intercept});
        }
    }
 
 
 
    rep(w, 0, m-1) {
        if (w) cout << ' ';
        cout << lichao.query(w);
    }
 
    return 0;
}
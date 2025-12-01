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
 
 
#define LEFT_STACK 0
#define RIGHT_STACK 1
 
 
// use monotonic stack to find less than values efficiently o(N)
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
 * differs from CHT because it does NOT require monotonic inputs
 */
class LiChao {
private:

    struct Line {
        ll slope;
        ll intercept;

        Line() {slope = 0, intercept = 0;};
        Line(long long m, long long b)
            : slope(m), intercept(b) {}

        inline ll evaluate(int x) const {
            return slope * (ll)x + intercept;
        }
    };


    struct TreeNode {
        Line storedLine;                // line information
        int leftChild = -1;             // index of leftChild Node in tree vector
        int rightChild = -1;            // index of rightChild Node in tree vector
    };


    int domainSize;                 // Number of x-values the tree spans (0 to domainSize-1)
    vector<TreeNode> tree;          // Dynamic array of nodes

    // adds new node to tree and returns the index of it's position in the segment tree
    int createNode(Line&& line) {
        tree.emplace_back(TreeNode{line});
        return tree.size() - 1;
    }

    /**
     * Internal recursive function to add a line over an interval.
     *
     * Parameters:
     *   nodeIndex                  – current node in the segment tree
     *   leftBound, rightBound      – segment interval covered by the current node
     *   queryLeft, queryRight      – the interval where we want to add the new line
     *   newLine                    – the line to insert
     */
    void addLineSegmentRecursive(
        int nodeIndex,
        int leftBound, int rightBound,
        int queryLeft, int queryRight,
        Line newLine
    ) {
        // No overlap (recurssive function went narrowed to far in one direction and now we can prune this path)
        if (queryRight < leftBound || rightBound < queryLeft)
            return;
        

        // Full cover: we attempt to insert into this node (current node interval matches interval needed for new line)
        if (queryLeft <= leftBound && rightBound <= queryRight) 
        {
            int mid = (leftBound + rightBound) >> 1;

            Line lowLine = tree[nodeIndex].storedLine;
            Line highLine = newLine;

            // Ensure lowLine(x) >= highLine(x) at leftBound
            if (lowLine.evaluate(leftBound) < highLine.evaluate(leftBound))
                swap(lowLine, highLine);

            // If lowLine is better everywhere on this interval, keep it (we already know that lowline is greater at leftbound from previous if statement so if it's also better here then it's obviously better everywhere!)
            if (lowLine.evaluate(rightBound) >= highLine.evaluate(rightBound)) {
                tree[nodeIndex].storedLine = lowLine;
                return;
            }

            // They cross inside the interval (lowLine is greater at left bound and highLine is greater at right bound) so we check the middle and set storeLine to greater value
            // whichever value is lesser will be sent to respective child to compete for a spot later on
            if (lowLine.evaluate(mid) >= highLine.evaluate(mid)) 
            {
                // lowLine is better on left half so we set stored line as we outlined in the comments above
                tree[nodeIndex].storedLine = lowLine;

                // no child to compare to so the lesser Line gets inserted and returned
                if (tree[nodeIndex].rightChild == -1) 
                    tree[nodeIndex].rightChild = createNode(Line{});

                // recurssively find the best node for highLine in the right child node
                addLineSegmentRecursive(
                    tree[nodeIndex].rightChild,
                    mid + 1, rightBound,
                    queryLeft, queryRight,
                    highLine
                );
            } 
            else 
            {
                // highLine is better on left half
                tree[nodeIndex].storedLine = highLine;

                // now we check the LEFT child and if no line then we can merely append Line
                if (tree[nodeIndex].leftChild == -1)
                    tree[nodeIndex].leftChild = createNode(Line{});

                // recurssively find the best node for lowLine the left child node
                addLineSegmentRecursive(
                    tree[nodeIndex].leftChild,
                    leftBound, mid,
                    queryLeft, queryRight,
                    lowLine
                );
            }

            return;
        }


        // Partial coverage → push down both sides (typically segment tree recurssion to find the intervals to add line)
        int mid = (leftBound + rightBound) >> 1;

        // add empty line for each child if their childs are empty so when we recurssively call them in a second it doesn't fail
        if (tree[nodeIndex].leftChild == -1)
            tree[nodeIndex].leftChild = createNode(Line{});

        if (tree[nodeIndex].rightChild == -1)
            tree[nodeIndex].rightChild = createNode(Line{});

        // use typical segment tree traversal for invertval [left, mid]
        addLineSegmentRecursive(
            tree[nodeIndex].leftChild,
            leftBound, mid,
            queryLeft, queryRight,
            newLine
        );

        // same idea but [mid+1, right]
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
    ll queryRecursive(int nodeIndex, int leftBound, int rightBound, int x) const {
        if (nodeIndex == -1)
            return 0;

        ll bestValue = tree[nodeIndex].storedLine.evaluate(x);
        if (leftBound == rightBound)
            return bestValue;

        int mid = (leftBound + rightBound) >> 1;

        if (x <= mid) 
            return max(bestValue, queryRecursive(tree[nodeIndex].leftChild, leftBound, mid, x));

        else 
            return max(bestValue, queryRecursive(tree[nodeIndex].rightChild, mid + 1, rightBound, x));
    }

public:


    // domainSize: number of X positions, valid x ∈ [0, domainSize - 1]
    LiChao(int _domainSize) : domainSize(_domainSize) {
        tree.emplace_back(TreeNode{});  // root node with default line
    }

    // adds a line y = m*x + b over interval [l, r].
    void addLineSegment(int l, int r, Line&& line) {
        addLineSegmentRecursive(0, 0, domainSize - 1, l, r, line);
    }

    // Queries the maximum value at the single point x.
    ll query(int x) const {
        ll result = queryRecursive(0, 0, domainSize - 1, x);
        return result;
    }
};




class Index_Input{ 
private:
    ll current_height;                  // Height of the current index
    int left_min_index;                 // Leftmost index where height v[i] is the minimum;
    int right_min_index;                // Rightmost index where height v[i] is the minimum; 
    int left_window_index;              // clamp earliest/latest to valid indicies
    int k;
    LiChao* lichao;



public:
    Index_Input(ll _ch, int _lmi, int _rmi, int _k, LiChao* _lichao) : current_height(_ch), left_min_index(_lmi+1), right_min_index(_rmi-1), k(_k), lichao(_lichao)
    {
        int Wlow = left_min_index - k + 1;
        left_window_index = max(0, Wlow);
    }

    void left_increasing() {
        int start_of_left_partial_overlap   = left_window_index;                                                            // the first index where the baord will increase in area (about to enter the window)
        int end_of_left_partial_overlap     = min(left_min_index-1, right_min_index - k + 1);                               // the last index where the board will increase in area
 
        if (start_of_left_partial_overlap <= end_of_left_partial_overlap) { 
            ll line_slope       = current_height;                                                                                   // area grows by h as window moves right (length increases)
            ll line_intercept   = current_height * (k - left_min_index);                                                            // Intercept: initial area at window start 
            (*lichao).addLineSegment(start_of_left_partial_overlap, end_of_left_partial_overlap, {line_slope, line_intercept});     // Add line to Li Chao tree for this segment
        }
    }


    void constant_full() {
        if (left_min_index + k > right_min_index) {
            ll constant_area = current_height * (right_min_index - left_min_index + 1);                         // Constant area: full segment covered but less than k
            (*lichao).addLineSegment(right_min_index-k+2, left_min_index-1, {0, constant_area});                // Add horizontal line to Li Chao tree
        }
    }

    void constant_cutoff() {
        int full_window_start = max(left_window_index, left_min_index);                                 // Earliest window start that fully covers this board
        int full_window_end   = min(right_min_index, right_min_index - k + 1);                          // Latest window start for full coverage
 
        if (full_window_start <= full_window_end) {                                                     // Only add if there exists a starting window index that captures the entire board
            ll constant_area = current_height * k;                                                      // Area = height * window length
            (*lichao).addLineSegment(full_window_start, full_window_end, {0, constant_area});           // Horizontal line for this interval
        }
    }

    void right_decreasing() {
        int start_of_right_partial_overlap  = max(left_min_index, right_min_index - k + 2);                     // the first index where the board will decrease in area
        int end_of_right_partial_overlap    = right_min_index;                                                  // the last index where the board will decrease in area (about to leave the window)
 
        if (start_of_right_partial_overlap <= right_min_index) {
            ll line_slope       = -current_height; 
            ll line_intercept   = current_height * (end_of_right_partial_overlap + 1); 
            (*lichao).addLineSegment(start_of_right_partial_overlap, end_of_right_partial_overlap, {line_slope, line_intercept});
        }
    }


};


 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    int n, k; cin >> n >> k;
 
    vi v(n), L(n), R(n);
    rep(i, 0, n-1) cin >> v[i];
 
    // find first values left and right of i stored in L[i] and R[i] that are less than v[i]
    fill_data(&v, &L, n, LEFT_STACK);
    fill_data(&v, &R, n, RIGHT_STACK);
 
    // no need to search past this point (no more valid windows)
    int m = n - k + 1; 
 
    // instantiate lichao 
    LiChao lichao{m};
 
    rep(i, 0, n-1) { 
        Index_Input idx{v[i], L[i], R[i], k, &lichao};

        // board will be referred to the range where current_height is the min value

        // window partially covers the board from the left side but will add more when window slides to the right
        idx.left_increasing();
 
        // window fully covers board - board is SMALLER than window in size/length (entire line segment is added to lichao)
        idx.constant_full();
 
        // board fully covers window - board is EQUAL TO OR BIGGER than window in size (the value of v[i]*window length is added to lichao) 
        idx.constant_cutoff();
 
        // same concept as the first segment but reversed. Window partially covers board but on the right side so as it moves away the area of the board will decrease.
        idx.right_decreasing();
    }
 
 
 
    rep(w, 0, m-1) 
        cout << lichao.query(w) << ' ';
    
 
    return 0;
}
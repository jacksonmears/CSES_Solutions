#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

using vi = vector<int32_t>;
using vvi = vector<vi>;
using pi = pair<int32_t, int32_t>;
using vpi = vector<pi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using vb = vector<bool>;
using vc = vector<char>;

#define pb push_back
#define rep(i,a,b) for (int i = a; i <= b; ++i)
#define repr(i,a,b) for (int i = a; i >= b; --i)

constexpr uint32_t MOD = 1e9 + 7;

class Segment {
public:
    int start, end;
    bool bit;

    Segment(int _start, int _end, int _bit) {
        start = _start;
        end = _end;
        bit = _bit;
    }

    bool operator<(const Segment& other) const {
        return start < other.start;
    }

    int length() const { return end - start + 1;}

};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; int m;
    cin >> s >> m;
    int n = s.size();

    set<Segment> segments;
    multiset<int> lens;

    // Build initial segments
    int st = 0;
    rep(i, 1, n) {
        if (i == n || s[i] != s[i - 1]) {
            segments.emplace(st, i - 1, s[i - 1] == '1');
            lens.insert(i - st);
            st = i;
        }
    }

    auto add_seg = [&](Segment seg) {
        segments.insert(seg);
        lens.insert(seg.length());
    };

    auto del_seg = [&](set<Segment>::iterator it) {
        lens.erase(lens.find(it->length()));
        segments.erase(it);
    };

    auto merge_left = [&](set<Segment>::iterator it) {
        if (it == segments.begin()) return it;
        auto prev = it;
        --prev;
        if (prev->bit == it->bit && prev->end + 1 == it->start) {
            Segment merged{prev->start, it->end, it->bit};
            del_seg(it);
            del_seg(prev);
            auto res = segments.insert(merged).first;
            lens.insert(merged.length());
            return res;
        }
        return it;
    };

    auto merge_right = [&](set<Segment>::iterator it) {
        auto nxt = it;
        ++nxt;
        if (nxt == segments.end()) return it;
        if (nxt->bit == it->bit && it->end + 1 == nxt->start) {
            Segment merged{it->start, nxt->end, it->bit};
            del_seg(nxt);
            del_seg(it);
            auto res = segments.insert(merged).first;
            lens.insert(merged.length());
            return res;
        }
        return it;
    };

    rep(i, 0, n-1) {
        int x; cin >> x; --x; // 0-based

        // Find the segment containing x
        auto it = segments.upper_bound({x, 0, 0});
        if (it == segments.begin()) continue;
        --it;
        if (it->end < x) continue;

        // Remove old segment
        Segment cur = *it;
        del_seg(it);

        // Flip bit at position x
        bool newbit = !cur.bit;

        // Split around x
        if (cur.start < x)
            add_seg({cur.start, x - 1, cur.bit});
        add_seg({x, x, newbit});
        if (x < cur.end)
            add_seg({x + 1, cur.end, cur.bit});

        // Merge adjacent same-bit segments
        auto mid = segments.lower_bound({x, 0, 0});
        if (mid == segments.end() || mid->start != x) {
            mid = segments.lower_bound({x - 1, 0, 0});
            if (mid != segments.begin()) --mid;
        }

        mid = merge_left(mid);
        mid = merge_right(mid);

        std::cout << *lens.rbegin() << " ";
    }

    std::cout << "\n";



    return 0;
}
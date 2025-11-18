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
constexpr ll infl = 1e10;

// couldn't figure this one out on my own so I did some research and found an incredible solution below!
// refactored solution for enhanced readability from TamimEhsan github repo: https://github.com/TamimEhsan/CSES-Solutions/blob/master/Advanced%20Techniques/Monster%20Game%20I.cpp

class Line{
public:
    //mx+c
    ll slope, intercept;
    Line(){slope=intercept=infl;}
    Line(ll m, ll c) : slope(m), intercept(c){}

    // returns the y value for a given x for this->line
    ll operator()(ll x){ return this->slope*x + this->intercept; }

    // check for lines with parallel slop
    bool operator==(Line& other) { return this->slope == other.slope; }

    //returns the xy-coordinates of intersection between two lines
    pldld operator>>(Line& other)
    {
        ld x,y;
        x=(ld)(other.intercept - this->intercept)/(this->slope - other.slope);
        y=(ld)this->slope*x + this->intercept;
        return {x,y};
    }
};


class MonotoneCHT{
private:
    deque<Line> Q;

    //Binary search over intersections to find the interval where x lies, {l, r} are the indices of the lines that define that interval
    pii bs(ll x)
    {
        int l = 0, r = (int)Q.size()-1;
        while(l+1 < r)
        {
            int mid=(l+r)/2;
            int intersection_x_value = (Q[mid-1]>>Q[mid]).first; 
            (intersection_x_value < x) ? l=mid : r=mid;
        }

        return {l,r};
    }

public:
    //handle parallel line insertion (front AND back),there cannot be more than one parallel line to new line currently inside Q;
    void insertBack(Line& nl)
    {
        // check for parallel line, if parallel and previous intercept is greater than pop_back (same slope and guarenteed worse result) or SKIP if vise versa for same reason of being unable to be better
        if(!Q.empty() && Q.back()==nl)
        {
            if(Q.back().intercept > nl.intercept) Q.pop_back();
            else return;
        }

        // while there are more than 1 lines check if intersection of last line and new line is less than intersection of second to last line and new line
        while(Q.size()>1 && (Q.back()>>nl) < (Q[Q.size()-2]>>nl))
            Q.pop_back();

        Q.emplace_back(nl);
    }


    // find the min y-slope value for an interval that contains the given x
    ll query(ll x)
    {
        // find interval
        auto [l, r] = bs(x);

        // find min y value from interval
        return min(Q[l](x), Q[r](x));
    }


    void clear(){ Q.clear(); }
};


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, x; cin>> n >> x;

    int monster[n], skill[n];

    rep(i, 0, n-1) cin >> monster[i];
    rep(i, 0, n-1) cin >> skill[i];

    MonotoneCHT cht{};
    Line base{x, 0};
    cht.insertBack(base);

    rep(i, 0, n-2){
        // init line with given skill[i] (slope) and optimal monster[i] (intercept)
        Line nl {skill[i], cht.query(monster[i])};

        // remove obsolete lines and push this to deque
        cht.insertBack(nl);
    }

    // return optimal value for monster[n-1] value
    cout << cht.query(monster[n-1]);


    return 0;
}
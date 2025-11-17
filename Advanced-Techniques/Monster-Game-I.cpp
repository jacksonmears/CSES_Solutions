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


class Line{
public:
    //mx+c
    ll slope, intercept;
    Line(){slope=intercept=infl;}
    Line(ll m, ll c) : slope(m), intercept(c){}

    ll operator()(ll x){ return this->slope*x + this->intercept; }

    // check for parallel slopes
    bool operator==(Line& other) { return this->slope == other.slope; }

    //assuming not parallel
    pldld intersect(Line& other)
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
    int type;


    //handle parallel line insertion (front AND back),there cannot be more than one parallel line to new line currently inside Q;
    void insertBack(Line& nl)
    {
        if(!Q.empty() && Q.back()==nl)
        {
            if((type<2 && Q.back().intercept > nl.intercept) || (type>=2 && Q.back().intercept<nl.intercept))
                Q.pop_back();
            else
                return;
        }

        while(Q.size()>1 && Q.back().intersect(nl) < Q[Q.size()-2].intersect(nl))
            Q.pop_back();

        Q.push_back(nl);
    }


    void insertFront(Line& nl)
    {
        if(!Q.empty() && Q[0]==nl)
        {
            if((type<2 && Q[0].intercept>nl.intercept) || (type>=2 && Q[0].intercept<nl.intercept))
                Q.pop_front();
            else
                return;
        }

        while(Q.size()>1 && Q[0].intersect(nl) > Q[1].intersect(nl))
            Q.pop_front();

        Q.push_front(nl);
    }


    // binary search
    pii bs(ll x)
    {
        if(Q.size()==1 || Q[0].intersect(Q[1]).first >= x) return {0,0};

        int l = 1, r = (int)Q.size()-1;
        while(l+1 < r)
        {
            int mid=(l+r)/2;
            (Q[mid].intersect(Q[mid-1]).first < x) ? l=mid : r=mid;
        }
        return {l,r};
    }


public:
    //slope increasing or decreasing(not query point,query point is arbitrary),querying for maximum or minimum
    MonotoneCHT(bool increasing, bool maximum)
    {
        type=increasing;
        if(maximum) type|=2;
    }


    inline void insert(Line& nl){(type==3||type==0) ? insertBack(nl) : insertFront(nl);}


    ll query(ll x)
    {
        pii index = bs(x);

        if(type<2) return min(Q[index.first](x), Q[index.second](x));
        return max(Q[index.first](x), Q[index.second](x));
    }


    void clear(){ Q.clear(); }
};


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n,x; cin>> n >> x;

    int monster[n], skill[n];

    rep(i, 0, n-1) cin >> monster[i];
    rep(i, 0, n-1) cin >> skill[i];

    MonotoneCHT cht(false,false);
    Line base{x, 0};
    cht.insert(base);

    rep(i, 0, n-2){
        Line nl {skill[i], cht.query(monster[i])};
        cht.insert(nl);
    }

    cout << cht.query(monster[n-1]);


    return 0;
}
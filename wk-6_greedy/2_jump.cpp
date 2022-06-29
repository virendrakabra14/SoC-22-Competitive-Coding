#include <bits/stdc++.h>
using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// Usage: insert, find, erase same as set;
// order_of_key(k): Number of items strictly smaller than k
// find_by_order(k): k-th element in a set (counting from zero)


// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// Usage: rng(), rng.min(), rng.max()

#define F first
#define S second
#define pb push_back
#define rz resize
#define mp make_pair
#define rep(i,a,b) for (int i=a; i<b; i++)
#define For(i,a,b) for(int i=a; i<b; i++)
#define Form(i,a,b) for(int i=a; i>b; i--)
#define modN 1000000007
#define fillv(v,x) fill(v.begin(),v.end(),x)
#define sortv(v) sort(v.begin(),v.end())
#define sortvf(v,objFunc) sort(v.begin(),v.end(),objFunc)
#define all(v) v.begin(),v.end()

typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef map<int,int> mii;
typedef unordered_map<int,int> umii;
typedef set<int> si;
typedef unordered_set<int> usi;

int jump(vi& a) {
    int n=a.size();
    int l=0, r=0;
    int steps=0;
    while(r<n-1) {
        int new_r=r;
        for (int i=l; i<r+1; i++) {
            new_r = max(new_r,i+a[i]);      // new farthest
        }
        if(r==new_r) return -1;     // not possible
        l=r+1;
        r=new_r;
        steps++;
    }
    return steps;
}

int main() {

    vi v{2,3,1,1,4};
    cout << jump(v) << '\n';    
    
}
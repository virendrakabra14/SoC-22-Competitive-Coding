#include <bits/stdc++.h>
using namespace std;

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

vvi adj;

vi dp1;
vi dp2;

void dfs(int i, int prev) {         // "prev" allows us to do away with the visited array (in case of trees)
    for (int j:adj[i]) {
        if(j!=prev) {
            dfs(j,i);               // recurse
        }
    }
    
    // finally, after processing all children, process this node
    // post-order traversal
        // dp1[i] = 1+ 2_max_values_in_dp2_of_i's_children
        // dp2[i] = 1+ max_val_in_dp2_of_i's_children
    
    // finding these max_values in single traversal
    int max_dp2=0, max2_dp2=0;
    for (int j:adj[i]) {
        if(j!=prev && dp2[j]>=max_dp2) {       // note the ">=" [e.g., 1,2,3,3,4,4, then both max and max2 must be 4]
            max2_dp2 = max_dp2;
            max_dp2 = dp2[j];
        }
    }
    dp1[i] = 1+max_dp2+max2_dp2;
    dp2[i] = 1+max_dp2;
}

int main() {
    
    int n; cin>>n;

    adj.clear(); adj.resize(n,vi(0));
    
    // visited.resize(n); fill(visited.begin(),visited.end(),false);
    // for trees, can do without visited array; by passing "parent" as argument in dfs

    dp1.resize(n); fillv(dp1,1);        // 1 is base-case for leaves
    dp2.resize(n); fillv(dp2,1);

    int u,v;
    for (int i=0; i<n-1; i++) {     // edges
        cin>>u>>v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    // WLOG, assume the tree to be rooted at 0
    dfs(0,-1);

    cout<<*max_element(dp1.begin(),dp1.end())<<'\n';

/*
11
1 2
1 3
1 4
2 5
2 6
10 7
11 7
3 7
8 4
4 9
*/


}
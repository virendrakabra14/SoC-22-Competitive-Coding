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

vvi dp;
// description below

int n,k;

void dfs(int v, int prev) {
    if(adj[v].size()==1) {      // leaf
        for (int j=2; j<k; j++) {
            dp[v][j]=0;             // any sub-tree of size>1 not possible
                                    // setting = 0 not really necessary, since already dp initialized with all 0s
        }
        return;
    }
    else {
        for (auto i:adj[v]) {
            if (i!=prev) {
                dfs(i,v);  // this fills up the i-th row of dp matrix   // ** think recursively
                
                        // try to update the current v-th row using the i-th row //
                // note: have to go from the back to the front, otherwise cases like below are problematic
                // 1-0-2 =>
                // consider i=1 and v=0 here
                // if we first make dp[0][2]=1 based on 1-0 (sub-tree of size 2)
                // then recurrence will make dp[0][3]=1 in this loop itself, even though there's no
                // sub-tree of size 3 yet [node 2 hasn't been traversed]

                // so, fill from the back
                // e.g. k=0,1,2,3 =>
                // k1=3,2,1,0; and for each k1, k2=k1,...,0

                for(int k1=k; k1>=2; k1--) {
                    for(int k2=k1-1; k2>=0; k2--) {
                        dp[v][k1]+=dp[v][k1-k2]*dp[i][k2];
                    }
                }

            }
        }
    }
}

int main() {
    
    cin>>n>>k;

    adj.resize(n); fillv(adj,vi(0));
    
    dp.resize(n); fillv(dp,vi(k+1,0));        // fill with all 0s initially
    // size n*(k+1)
    // dp[i][j] = no. of sub-trees of size j that can be obtained by "including i", and using any of the nodes "below" it

    // size=0 subtrees: 0
    // base case : size=1 sub-trees => only sub-tree is the node i itself
    for (int i=0; i<n; i++) {
        dp[i][0]=0;
        dp[i][1]=1;
    }

    int u,v;
    for (int i=0; i<n-1; i++) {     // edges
        cin>>u>>v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(0,-1);

    for (int i=0; i<n; i++) {
        for (int j=0; j<k+1; j++) {
            cout<<dp[i][j]<<'\t';
        }
        cout<<'\n';
    }

    int ans=0;
    for (int i=0; i<n; i++) {
        ans+=dp[i][k];
    }
    cout<<ans<<'\n';

/*

3 3
1 2
1 3

5 4
1 2
1 3
1 4
4 5
*/

}
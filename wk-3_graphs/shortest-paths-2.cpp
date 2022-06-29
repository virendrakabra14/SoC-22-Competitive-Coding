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
#define modN 1000000007

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
typedef map<int,int> mii;
typedef unordered_map<int,int> umii;
typedef set<int> si;
typedef unordered_set<int> usi;

vector<vector<ull> > adj;
vector<vector<int> > dist;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(0);


    int n,m,q; cin>>n>>m>>q;

    adj.rz(n,vector<ull>(n,ull(1e12+1ull)));

    int u,v,w;
    for (int j=0; j<m; j++) {
        cin>>u>>v>>w;
        u--; v--;
        if(w<adj[u][v]) {           // there's a testcase with multi-edges
            adj[u][v]=w;
            adj[v][u]=w;
        }
    }

    for (int i=0; i<n; i++) {
        adj[i][i]=0;
    }

    for (int i=0; i<n; i++) {           // i-th node is intermediate
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                adj[j][k] = min( adj[j][k], adj[j][i]+adj[i][k] );
            }
        }
    }

    for (int i=0; i<q; i++) {
        cin>>u>>v;
        u--; v--;
        if(adj[u][v]>1e12) cout<<"-1\n";
        else cout<<adj[u][v]<<"\n";
    }

}
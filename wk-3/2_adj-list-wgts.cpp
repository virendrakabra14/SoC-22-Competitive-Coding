#include <bits/stdc++.h>
using namespace std;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// Usage: rng(), rng.min(), rng.max()

#define F first
#define S second
#define pb push_back
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

int main() {

    int n; cin>>n;      // number of nodes

    // we'll consider nodes numbered 0...(n-1)

    vector<vector<pii> > adj;
    adj.resize(n,vector<pii>(0));
    
    int m; cin>>m;               // number of edges
    int u,v,w;
    for (int i=0; i<m; i++) {
        cin>>u>>v>>w;       // w is weight of this edge u->v

        adj[u].pb({v,w});       // storing v,w as a pair; this means: u->v, with wgt w
        // if undirected, then store u->v, and v->u
        // adj[v].pb({u,w});
    }

    for (int i=0; i<adj.size(); i++) {
        for (auto j : adj[i]) {
            cout<<i<<"->"<<j.first<<','<<j.second<<"\t";
        }
    }
    
}

/*
input (see pdf doc for graph structure) :
6 7
0 1 2
0 4 4
1 2 1
4 3 7
5 0 5
3 2 8
5 1 9
*/
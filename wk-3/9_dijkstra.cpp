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

vector<vector<pii> > adj;
vi dist;        // final distances
vb processed;

int main() {

    int n,m; cin>>n>>m;     // n=|V|, m=|E|
    int src; cin>>src;      // source
    src--;                  // 0-indexing of vertices

    adj.resize(n,vector<pii>(0));

    int u,v,w;
    for (int i=0; i<m; i++) {
        cin>>u>>v>>w;
        u--; v--;           // 0-indexing
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }

    priority_queue<pii,vector<pii>,greater<pii> > q;        // min priority queue
    // will compare the first elements of the pairs
    // greater<pii>, to get min. elem. at top

    // pairs of the form (d,x), meaning that the current distance to node x is d

    dist.resize(n,INT_MAX/2);       // /2 done because doing (...)+w later, which will become large negative
                                    // if (...) is INT_MAX (and w>0)
    processed.resize(n,false);

    dist[src]=0;
    q.push({0,src});

    while(!q.empty()) {                  // do till all nodes not get processed
        int x = q.top().second;   // that unprocessed node, which has minimum dist currently (from src)
        q.pop();
        processed[x]=true;
        for (auto i:adj[x]) {
            v = i.first;
            w = i.second;
            if (dist[x]+w < dist[v]) {      // this won't be true for any 'processed' nodes
                                            // this can be seen in correctness proof of Dijkstra
                                            // so checking !processed[i] is actually redundant
                dist[v] = dist[x]+w;
                q.push({dist[v],v});
                // note: we might be pushing this v multiple times throughout the run
                // however, each instance of v would have a different pair.first value (i.e. distance)
                // since the latest dist[v] would be smallest, so priority_queue will process this instance 
                // sooner than any other instance of v.
                // Thus, correct.
            }
        }
    }

    for (int i=0; i<n; i++) {
        cout<<i+1<<' '<<dist[i]<<"\n";
    }

/*
5 6 1
2 3 2
3 4 6
2 1 5
1 4 9
1 5 1
4 5 2
(same as in doc/book)
*/

}
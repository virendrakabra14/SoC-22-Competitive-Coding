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

vi dist;
vi prev_dist;
vector<pair<pii,int> > edges;

int main() {

    int n,m,src; cin>>n>>m>>src;     // n=|V|, m=|E|

    dist.rz(n,INT_MAX/2);
    edges.resize(2*m);      // undirected

    int u,v,w;
    for (int i=0; i<2*m; i+=2) {
        cin>>u>>v>>w;
        u--; v--;
        edges[i]={{u,v},w};
        edges[i+1]={{v,u},w};
    }

    dist[src]=0;        // all dist.s from src

    for (int i=0; i<n; i++) {       // will stabilize in at most n-1 rounds
                                    // n rounds for checking negative cycle
        prev_dist=dist;     // check if stabilized?

        bool stable=1;

        // iterate over all edges in each round
        for (auto e:edges) {
            u=e.first.first;
            v=e.first.second;
            w=e.second;
            
            dist[u]=min(dist[u],dist[v]+w);     // INT_MAX+w will be large negative; hence dist initialized with INT_MAX/2
            
            if(dist[u]<prev_dist[u]) {
                stable=0;
                if(i==n-1) {
                    cout<<"neg cycle\n";
                    break;
                }
            }
        }

        if(stable) {
            cout<<i+1<<" rounds\n";
            break;
        }

    }

    for (int i=0; i<n; i++) {
        cout<<i<<' '<<dist[i]<<'\n';
    }

/*
5 7 0
1 3 1
1 2 2
1 4 7
3 4 3
2 4 3
2 5 5
4 5 2
-----
4 5 0
1 2 3
1 3 5
2 3 2
3 4 -7
4 1 2
-----
(book graphs)
*/



}
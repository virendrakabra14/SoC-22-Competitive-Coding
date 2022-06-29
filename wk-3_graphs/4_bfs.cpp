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

vvi adj;
vb visited;
vi dist;        // all distances from source

int main() {

    int n,m; cin>>n>>m;     // n=|V|, m=|E|

    adj.resize(n,vi(0));

    int u,v;
    for (int i=0; i<m; i++) {
        cin>>u>>v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    visited.rz(n,false);
    dist.rz(n);

    int src=0;
    dist[src]=0;

    queue<int> Q;
    Q.push(src);
    visited[src]=1;                     // change: make it visited

    while(!Q.empty()) {
        int x = Q.front();
        Q.pop();
        // visited[x]=1;                // not here
        for (auto i:adj[x]) {
            if(!visited[i]) {
                visited[i]=1;           // change: make it visited here itself
                dist[i] = dist[x]+1;
                Q.push(i);
            }
        }
    }

    cout<<"---\n";
    for (int i=0; i<n; i++) {
        cout<<i+1<<' '<<dist[i]<<"\n";
    }

/*
6 6
1 2
1 4
2 3
2 5
5 6
3 6
(book diagram, same in doc)
*/



}
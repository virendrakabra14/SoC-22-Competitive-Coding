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

vb visited;
vvi adj;
vi arrival, departure, parent;

int time1=0;

void dfs(int v) {               // if not using adj, etc. as global var.s,
                                // then remember to pass by reference (or using pointers)
                                // passing by value copies entire stuff, so increases execution time
    arrival[v]=time1;
    time1++;
    for(auto i:adj[v]) {
        if(!visited[i]) {
            visited[i]=1;               // make visited here
            dfs(i);     // recursion
            parent[i]=v;
        }
    }
    departure[v]=time1;
}

int main() {

    int n,m; cin>>n>>m;     // n=|V|, m=|E|

    adj.resize(n,vi(0));

    int u,v;
    for (int i=0; i<m; i++) {
        cin>>u>>v;
        u--; v--;       // 0-indexing of vertices
        adj[u].pb(v);
        adj[v].pb(u);
    }

    visited.resize(n,false);
    arrival.rz(n,0);
    departure.rz(n,0);
    parent.rz(n,0);

    for (int i=0; i<n; i++) {           // loop, in case there are more than 1 connected components
        if(!visited[i]) {
            visited[i]=1;               // make visited here
            dfs(i);
            parent[i]=-1;
        }
    }

    for (int i=0; i<n; i++) {
        cout<<i+1<<' '<<arrival[i]<<' '<<departure[i]<<' '<<parent[i]+1<<"\n";
    }

}

/*
5 5
1 2
1 4
3 5
2 5
3 2
(book graph)
*/
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
bool cycle=0;

void dfs(int curr, int prev) {
    visited[curr]=1;
    for(auto i:adj[curr]) {
        if(i!=prev && visited[i]) {     // not "just previous" one, AND visited   => cycle
                                        // see diagram
            cycle=1;
            return;
        }
        if(!cycle && !visited[i]) dfs(i,curr);
    }
}

int main() {

    int n,m; cin>>n>>m;     // n=|V|, m=|E|

    adj.resize(n,vi(0));

    int u,v;
    for (int i=0; i<m; i++) {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    visited.resize(n,false);

    for (int i=0; i<n; i++) {           // loop, in case there are more than 1 connected components
        if(cycle) break;
        if(!visited[i]) dfs(i,-1);
    }

    if(cycle) cout<<"cycle is present\n";
    else cout<<"acyclic\n";

}

/*
5 6
0 2
0 3
2 3
1 2
1 4
2 4
(book graph)
*/
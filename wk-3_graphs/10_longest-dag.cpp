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

vi state;
vvi adj;
bool cycle;
vi longest;

vi sorted(0);

void topSort(int i) {
    if(state[i]==1) {       // reach a node "in processing" => (directed) cycle present
        cycle=1;
        return;
    }
    else if(state[i]==0) {
        state[i]=1;         // in processing
        for (auto j:adj[i]) {
            topSort(j);
        }
        state[i]=2;         // processing complete
        sorted.pb(i);
    }
}

int main() {
    
    int n,m; cin>>n>>m;     // n=|V|, m=|E|

    adj.resize(n,vi(0));
    state.resize(n,0);
    
    int u,v;
    for (int i=0; i<m; i++) {
        cin>>u>>v;
        u--; v--;
        adj[u].pb(v);       // DAG: directed
    }

    for (int i=0; i<n; i++) {
        if(state[i]==0)         // didn't start processing
            topSort(i);
    }
    reverse(sorted.begin(),sorted.end());

    if(cycle) {cout<<"cycle\n"; return 0;}

    longest.resize(n,0);

    for(int i:sorted) {
        for(int j:adj[i]) {
            longest[j]=max(longest[j],longest[i]+1);
        }
    }
    cout << "longest path length: " << *max_element(longest.begin(),longest.end())<<"\n";



/*
7 7
2 1
1 3
3 4
3 5
7 6
5 6
1 6
4
(see doc for figure)
*/

    
}
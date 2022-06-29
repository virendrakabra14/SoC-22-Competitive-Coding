#include <bits/stdc++.h>
using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// Usage: insert, find, erase same as set;
// order_of_key(k): Number of items strictly smaller than k
// find_by_order(k): k-th element in a set (counting from zero)


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
#define all(v) v.begin(),v.end()

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

///

typedef pair<pair<int,int>,int> edge_type;

vector<edge_type> edges;     // edge list representation
vector<int> parent;
vector<int> size;

struct sort_edges {
    inline bool operator() (const edge_type& edge1, const edge_type& edge2) {
        return edge1.second < edge2.second;
    }
};

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

int get(int v) {
    if (v==parent[v]) return v;
    return parent[v] = get(parent[v]);      // path compression
}

void union_sets(int a, int b) {     // union by size heuristic
    a = get(a);
    b = get(b);
    if(a!=b) {                      // don't union if in same sets
        if(size[a]<size[b]) swap(a,b);
        parent[b] = a;              // merge smaller into larger
        size[a] += size[b];
    }
}

int main() {

    edges.clear();
    parent.clear();

    int n, m;
    cin>>n>>m;

    edges.resize(m);
    parent.resize(n);
    size.resize(n);

    for (int i=0; i<n; i++) {
        make_set(i);
    }

    int u,v,w;      // (u,v) with weight w;
    for (int i=0; i<m; i++) {
        cin>>u>>v>>w;
        u--; v--;
        edges[i] = {{u,v},w};       // make_pair(make_pair(u,v),w)
    }

    sort(edges.begin(), edges.end(), sort_edges());     // sorts edges in ascending order of weights

    vector<edge_type> mst_edges(0);

    for (int i=0; i<m; i++) {                   // iterate over all edges
        if(mst_edges.size() == n-1) break;      // |V|-1
        u = edges[i].first.first;
        v = edges[i].first.second;
        w = edges[i].second;
        if (get(u)!=get(v)) {
            mst_edges.push_back(edges[i]);
            union_sets(u,v);
        }
    }

    int weight = 0;

    for (int i=0; i<n-1; i++) {
        cout << mst_edges[i].first.first+1 << ' ' << mst_edges[i].first.second+1 << '\n';
        weight += mst_edges[i].second;
    }
    cout << weight << '\n';

}

/*
Example in doc
6 10
1 2 5
2 3 1
1 3 6
3 4 1
5 3 5
4 3 10
3 6 3
5 6 4
1 4 4
4 6 4
*/
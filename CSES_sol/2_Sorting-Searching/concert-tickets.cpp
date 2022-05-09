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

void solve() {
    
}

void precalc() {
    
}

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n,m; cin>>n>>m;
    // vull h(n),t(m);     // TLE using vector of tickets... use multiset
    multiset<int> h;
    
    int x;
    for (int i=0; i<n; i++) {
        cin>>x;
        h.insert(x);
    }

    int y;
    for (int i=0; i<m; i++) {
        cin>>y;
        auto x = h.upper_bound(y);      // upper_bound: Returns iterator pointing to the first element greater than argument, or end().
        if(x==h.begin()) {              // if it is the first ticket (smallest price currently), then can't be given
                                        // to this customer [note the "upper_bound" definition]
            cout<<"-1\n";
        }
        else {
            x--;                        // since we need a smaller number, so x--
            cout<<*(x)<<"\n";
            h.erase(x);
        }
    }
    
}
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

struct my_struct {
    int x,y;
    bool operator<(const my_struct &p) {
        if (x == p.x) return y < p.y;
        else return x < p.x;            // first according to x, then by y
    }
};

bool comp(vi a, vi b) {
    if (a.size() == b.size()) return a < b;
    else return a.size() < b.size();
}

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // precalc();
    
    // int t; cin>>t;
    // while(t--) solve();
    
    int i=0, j=1;

    my_struct a; a.x=i; a.y=j; i++; j--;
    my_struct b; b.x=i; b.y=j; i--; j--;
    my_struct c; c.x=i; c.y=j; i--; j--;
    my_struct d; d.x=i; d.y=j; i++; j--;
    
    my_struct m1[] = {a,b,c,d};
    int n = sizeof(m1)/sizeof(my_struct);

    for (int i=0; i<n; i++) {
        cout<<m1[i].x<<' '<<m1[i].y<<"\n";
    }
    cout<<"-------\n";

    sort(m1,m1+n);

    for (int i=0; i<n; i++) {
        cout<<m1[i].x<<' '<<m1[i].y<<"\n";
    }

    // comp compares vectors by their sizes...
    
}
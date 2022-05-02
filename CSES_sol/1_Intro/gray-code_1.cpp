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
    
    // precalc();
    
    // int t; cin>>t;
    // while(t--) solve();
    
    int n; cin>>n;

    vs v(2);
    v[0]="0";
    v[1]="1";

    for (int i=0; i<n-1; i++) {
        for (int i=v.size()-1; i>=0; i--) {     // pb entire vector in reverse
            v.pb(v[i]);
        }
        for (int i=0; i<v.size()/2; i++) {      // append 0 to first half (at the start of each string)
            v[i]="0"+v[i];
        }
        for (int i=v.size()/2; i<v.size(); i++) {   // append 1 to later half (again at start)
            v[i]="1"+v[i];
        }
    }

    for (int i=0; i<(1<<n); i++) {      // left-shift operator (same as *=2 if not overflowed)
        cout<<v[i]<<"\n";
    }
    
}
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
    ll n,x; cin>>n>>x;
    vll p(n);
    for (int i=0; i<n; i++) {
        cin>>p[i];
    }
    sort(p.begin(),p.end());
    
    int i=0,j=n-1;      // 2 markers
    int count=0;

    while(i<=j) {
        if(i>=j) {
            break;
        }
        if(p[j]+p[i]<=x) {
            count++;
            i++;
            j--;
        }
        else {
            count++;
            j--;
        }
    }
    if(i==j) count++;
    cout<<count<<"\n";

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
    
    solve();
    
}
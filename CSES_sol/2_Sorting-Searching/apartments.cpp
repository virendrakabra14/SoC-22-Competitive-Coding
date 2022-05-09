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
    int n,m,k; cin>>n>>m>>k;
    vi size(n), aval(m);
    for (int i=0; i<n; i++) {
        cin>>size[i];
    }
    for (int j=0; j<m; j++) {
        cin>>aval[j];
    }
    sort(size.begin(),size.end());
    sort(aval.begin(),aval.end());
    int count1=0;
    int inAval=0;
    int i=0;
    while(i<n && inAval<m) {
        if(size[i]<=aval[inAval]+k && size[i]>=aval[inAval]-k) {
            count1++;
            i++;
            inAval++;
        }
        else if(size[i]>aval[inAval]+k) {inAval++;}
        else if(size[i]<aval[inAval]-k) {i++;}
        // if(inAval>=m) break;
    }
    cout<<count1<<"\n";
}

void precalc() {
    
}

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // precalc()
    
    // int t; cin>>t;
    // while(t--) solve();
    solve();
    
}
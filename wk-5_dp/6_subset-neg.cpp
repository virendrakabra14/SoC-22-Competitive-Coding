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
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;

void solve() {

    int n,b; cin>>n>>b;
    vi a(n);
    int neg=0,pos=0;
    for (int i=0; i<n; i++) {
        cin>>a[i];
        pos+= (a[i]>0 ? a[i] : 0);
        neg+= (a[i]<0 ? a[i] : 0);
    }
    vvi dp(n+1,vi(pos-neg+1));      // neg to 0 to pos

    for (int i=0; i<n+1; i++) {
        for (int j=0; j<pos-neg+1; j++) {
            if (i==0) dp[i][j]= (j==0-neg ? 1 : 0);
            else dp[i][j] = max(dp[i-1][j], ((j-a[i-1]>=0 && j-a[i-1]<pos-neg+1) ? dp[i-1][j-a[i-1]] : INT_MIN));
        }
    }

    cout<<dp[n][b-neg]<<"\n";
    for (int i=0; i<n+1; i++) {
        for (int j=0; j<pos-neg+1; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    
}

void precalc() {
    
}

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // precalc()
    
    int t; cin>>t;
    while(t--) solve();
    
    
}
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
typedef vector<vector<string> > vvs;
typedef vector<vector<bool> > vvb;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef unordered_map<int,int> umii;
typedef set<int> si;
typedef unordered_set<int> usi;

int n=7;
int count1=0;
// vvb visited(n,vb(n,0));       // causing TLE!!
bool visited[7][7]={false};     // ={0} makes first element 0, and since all others not specified => set to 0

string s;

// bool ok(int i) {
//     return (i>=0 && i<n);
// }
#define ok(i) (i>=0 && i<n)

void solve(int i, int j, int moves) {
    // cout<<n<<' '<<i<<' '<<j<<' '<<moves<<"\n";
    if(i==n-1 && j==0 && moves==n*n-1) {count1++; return;}
    if(i==n-1 && j==0 && moves<n*n-1) {return;}
    if(moves>=n*n-1) {return;}
    // walls, and partitioned...
    if(ok(i-1) && ok(j) && ok(i+1) && !ok(j+1) && visited[i][j-1] && !visited[i-1][j] && !visited[i+1][j]) {return;}
    if(ok(i-1) && ok(j) && ok(i+1) && !ok(j-1) && visited[i][j+1] && !visited[i-1][j] && !visited[i+1][j]) {return;}
    if(ok(i) && ok(j+1) && ok(j-1) && !ok(i-1) && visited[i+1][j] && !visited[i][j-1] && !visited[i][j+1]) {return;}
    if(ok(i) && ok(j+1) && ok(j-1) && !ok(i+1) && visited[i-1][j] && !visited[i][j-1] && !visited[i][j+1]) {return;}
    // return in between (partitioned...)
    if(ok(i-1) && ok(i+1) && ok(j-1) && ok(j+1)) {
        if(visited[i][j-1] && visited[i][j+1] && !visited[i-1][j] && !visited[i+1][j]) {return;}
        if(visited[i-1][j] && visited[i+1][j] && !visited[i][j-1] && !visited[i][j+1]) {return;}
    }
    // recurse
    visited[i][j]=1;
    if((s[moves]=='L' || s[moves]=='?') && ok(i) && ok(j-1) && !visited[i][j-1]) solve(i,j-1,moves+1);
    if((s[moves]=='U' || s[moves]=='?') && ok(i-1) && ok(j) && !visited[i-1][j]) solve(i-1,j,moves+1);      // if ok(..) returns false, then won't compute rest of terms, so √
    if((s[moves]=='D' || s[moves]=='?') && ok(i+1) && ok(j) && !visited[i+1][j]) solve(i+1,j,moves+1);
    if((s[moves]=='R' || s[moves]=='?') && ok(i) && ok(j+1) && !visited[i][j+1]) solve(i,j+1,moves+1);
    visited[i][j]=0;        // backtracking
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
    // memset(visited,0,sizeof(visited)/sizeof(bool));
    cin>>s;
    // cin>>n;       // put n>=2
    solve(0,0,0);
    cout<<count1<<"\n";
    
}
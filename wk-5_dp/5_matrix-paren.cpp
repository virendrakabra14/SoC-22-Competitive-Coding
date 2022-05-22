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

// CLRS : 375

void printParen(vvi s, int i, int j) {          // ** recursive
    if (i==j) {cout<<i; return;}
    if (i<j) {
        cout<<"(";
        printParen(s,i,s[i][j]);
        printParen(s,s[i][j]+1,j);
        cout<<")";
    }
}

void solve() {
    int n; cin>>n;
    vi p(n+1);                      // matrix dimensions p[i]xp[i+1] for A_i
    for (int i=0; i<n+1; i++) {
        cin>>p[i];
    }
    vvi dp(n,vi(n,INT_MAX));        // nxn matrix
    vvi s(n,vi(n));

    // base cases:
    for (int i=0; i<n; i++) {
        dp[i][i]=0;
    }

    for (int l=2; l<=n; l++) {          // length Ai...Aj
        for (int i=0; i<n; i++) {
            int j = l+i-1;
            if (j>=n) continue;
            for (int k=i; k<j; k++) {
                int temp = dp[i][k]+dp[k+1][j]+ p[i]*p[k+1]*p[j+1];
                if (dp[i][j]>temp) {
                    dp[i][j]=temp;
                    s[i][j]=k;      // storing k, to get the actual parenthesization later
                }
            }
        }
    }

    cout<<dp[0][n-1]<<"\n";
    printParen(s,0,n-1);

}

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    solve();

/*
4
40 20 30 10 30
*/


}
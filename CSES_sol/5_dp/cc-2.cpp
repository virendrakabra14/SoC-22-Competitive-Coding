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
#define For(i,a,b) for(int i=a; i<b; i++)
#define Form(i,a,b) for(int i=a; i>b; i--)
#define modN 1000000007
#define fillv(v,x) fill(v.begin(),v.end(),x)
#define sortv(v) sort(v.begin(),v.end())
#define sortvf(v,objFunc) sort(v.begin(),v.end(),objFunc)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

// ll dp[1000001][101];       // global arrays not limited by stack size
// int c[101];

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n,x; cin>>n>>x;
    // int c[n];

    vvi dp(x+1,vi(n+1));
    vi c(n);

    for (int i=0; i<n; i++) {
        cin>>c[i];
    }
    
    // int dp[x+1][n+1];   // 1st row and 1st col are base-cases

    // using 0 types of coins
    for (int i=0; i<x+1; i++) {
        dp[i][0]=0;
    }
    // sum=0 can be formed in 1 way
    for (int j=0; j<n+1; j++) {
        dp[0][j]=1;
    }

    for (int i=1; i<x+1; i++) {
        for (int j=1; j<n+1; j++) {
            // dp[i][j] = (distinct) no. of ordered ways to get i using only the first j types of coins
            // dp[i][j] = ((i-c[j-1]>=0 ? dp[i-c[j-1]][j] : 0) + dp[i][j-1])%modN;      // TLE
            dp[i][j] = dp[i][j-1];
            if (i-c[j-1]>=0) {
                ( dp[i][j] += dp[i-c[j-1]][j] ) %= modN;
                // dp[i][j] %= modN;
            }
        }
    }
    
    // for (int i=0; i<x+1; i++) {
    //     for (int j=0; j<n+1; j++) {
    //         cout<<dp[i][j]<<'\t';
    //     }
    //     cout<<'\n';
    // }
    
    cout<<dp[x][n]<<'\n';
    
}
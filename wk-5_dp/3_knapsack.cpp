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



int main() {

    int n,W; cin>>n>>W;
    int w[n],p[n];              // weights and prices
    for (int i=0; i<n; i++) {
        cin>>w[i];
    }
    for (int i=0; i<n; i++) {
        cin>>p[i];
    }

    int dp[n+1][W+1];           // dp[i][j] = max price that we can get from first i items, and bag of capacity j

    // base cases:
    
    // if 0 items, then sum of prices of items taken = 0
    for (int j=0; j<W+1; j++) {
        dp[0][j]=0;
    }

    // if bag's capacity is 0, then price we can get = 0
    for (int i=0; i<n+1; i++) {
        dp[i][0]=0;
    }

    for (int i=1; i<n+1; i++) {         // note i,j start after base-case indices
        for (int j=1; j<W+1; j++) {
            dp[i][j] = max( (j-w[i-1]>=0 ? (dp[i-1][j-w[i-1]]+p[i-1]) : INT_MIN/2), dp[i-1][j] );

            // INT_MIN (or any small number), because it can't affect max then

            // this is same as:
            /*
                if j-w[i-1] >= 0, then dp[i][j] = max(...,...)
                else, dp[i][j] = second term
            */

        }
    }

    for (int i=0; i<n+1; i++) {
        for (int j=0; j<W+1; j++) {
            cout<<dp[i][j]<<'\t';
        }
        cout<<'\n';
    }
    cout<<"----------------------------------------------------\n";

    // only 2 rows suffice
    int dp2[2][W+1];
    
    // base cases:
    // 0 items
    for (int j=0; j<W+1; j++) {
        dp2[0][j]=0;
    }
    // 0 capacity:
    for (int i=0; i<2; i++) {
        dp2[i][0]=0;
    }

    // now fill in:
    for (int i=1; i<n+1; i++) {
        for (int j=1; j<W+1; j++) {
            // use mod 2
            dp2[i%2][j] = max( (j-w[i-1]>=0 ? (dp2[(i-1)%2][j-w[i-1]]+p[i-1]) : INT_MIN), dp2[(i-1)%2][j] );

            // note that here i>=1, so (i-1)%2 works, but in case (i-1) may be -1, then use (i-1 + 2)%2
        }
    }

    // required answer: dp2[n%2][W] 

    for (int i=0; i<2; i++) {
        for (int j=0; j<W+1; j++) {
            cout<<dp2[i][j]<<'\t';
        }
        cout<<'\n';
    }


/*
4 8
3 4 6 5
2 3 1 4
*/
// optimal solution: first and last items

}
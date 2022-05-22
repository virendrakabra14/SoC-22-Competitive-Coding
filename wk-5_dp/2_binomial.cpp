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

ull Choose(int n, int k) {
    ull dp[n+1][k+1];       // can use vector of vectors too

    // base cases

    for (int j=1; j<k+1; j++) {
        dp[0][j]=0;             // 0Cj
    }

    for (int i=0; i<n+1; i++) {
        dp[i][0]=1;             // iC0
    }

    for (int i=1; i<n+1; i++) {         // note that started filling from "after the base-cases"
        for (int j=1; j<k+1; j++) {
            dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
        }
    }

    for (int i=0; i<n+1; i++) {
        for (int j=0; j<k+1; j++) {
            cout<<dp[i][j]<<'\t';
        }
        cout<<'\n';
    }

    return dp[n][k];

}

int main() {
    int n,k; cin>>n>>k;
    cout<<Choose(n,k)<<'\n';
}
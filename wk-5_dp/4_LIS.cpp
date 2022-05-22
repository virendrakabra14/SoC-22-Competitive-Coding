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

    int n; cin>>n;

    int a[n];
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }

    int dp[n];
    fill(dp,dp+n,1);        // init to 1

    for (int i=1; i<n; i++) {       // start from 1
        for (int j=0; j<i; j++) {
            dp[i] = max( dp[i], (a[j]<=a[i] ? (dp[j]+1) : INT_MIN) );
        }
    }

    for (int i=0; i<n; i++) {
        cout<<dp[i]<<' ';
    }
    cout<<'\n';

    cout<<"Answer: "<<*max_element(dp,dp+n)<<'\n';

/*
9
10 22 9 33 21 50 41 60 80
*/

}
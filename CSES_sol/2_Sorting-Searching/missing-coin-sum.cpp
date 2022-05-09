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
    
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // pracC:72

    int n; cin>>n;
    vll v(n);
    for (int i=0; i<n; i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());

    if(v[0]>1) {
        cout<<1<<"\n";
        return 0;
    }

    // we know v[0]=1
    int i=1;        // second index
    ull prev=1;        // 1...k can be formed from a[0]...a[i-1], and k+1 CANNOT
    ull curr=1;

    // TLE

    // while(i<n) {
    //     if(prev+1ull-v[i] < 0) {
    //         cout<<prev+1<<"\n";        // bcoz hv sorted
    //         return 0;
    //     }
    //     else {
    //         if (curr+1ull-v[i] <= prev) {
    //             curr++;
    //             continue;
    //         }
    //         else {
    //             prev=curr;
    //             i++;
    //         }
    //     }
    // }

    vll dp(n);
    dp[0]=1;
    for (int i=1; i<n; i++) {

        // for (int i=0; i<n; i++) {
        //     cout<<dp[i]<<' ';
        // }
        // cout<<"\n";

        if(v[i]-dp[i-1] > 1) {
            cout<<dp[i-1]+1<<"\n";
            return 0;
        }
        else {
            dp[i]=dp[i-1]+v[i];
        }
    }

    // for (int i=0; i<n; i++) {
    //     cout<<dp[i]<<' ';
    // }
    // cout<<"\n";
    
    // cout<<prev+1<<"\n";
    cout<<dp[n-1]+1<<"\n";

    
}
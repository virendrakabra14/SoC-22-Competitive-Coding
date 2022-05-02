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

vll v(20);

ll calc1(ll currSum, ll total, int i) {
    if(i==0) return (abs(total-2*currSum));
    return min(calc1(currSum,total,i-1),calc1(currSum+v[i-1],total,i-1));
}

void solve() {
    int n; cin>>n;      // NOTE: n<=20
                        // exponential algo will work
    ll sum=0;
    for (int i=0; i<n; i++) {
        cin>>v[i];
        sum+=v[i];
    }
    cout<<calc1(0,sum,n)<<"\n";
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
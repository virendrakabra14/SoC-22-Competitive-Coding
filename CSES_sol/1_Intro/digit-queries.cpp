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
    int n; cin>>n;
    ll x;
    for (int i=0; i<n; i++) {
        cin>>x;
        if(x<=9) {cout<<x<<"\n"; continue;}
        ll n2=1;
        ll n3=9;
        ll n4=9;
        ll n5=n4;
        int j;
        for (j=0; j<100; j++) {     // 100 is arbit large
            if (n4>=x) break;
            n5=n4;
            n2*=10;
            n3=9*(n2*(j+2));
            n4+=n3;
            // cout<<n2<<' '<<n3<<' '<<n4<<' '<<n5<<"\n";
        }
        x-=n5;
        ll y=x;         // ll, AND NOT int
        y-=1;
        y/=(j+1);       // j = num_digits in that number...
        int z=(x-1)%(j+1);
        n2+=(y);
        string s=to_string(n2);
        // cout<<x<<' '<<y<<' '<<z<<' '<<s<<"\n";
        cout<<s[z]<<"\n";
    }
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
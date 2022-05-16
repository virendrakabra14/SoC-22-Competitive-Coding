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

ll n,l,r;

// https://www.geeksforgeeks.org/builtin-functions-gcc-compiler/

ll num_positions(ll n) {
    ll floor_log2 = 8*sizeof(ll) - __builtin_clzll(n) - 1;          // clz: count leading zeros (long long)
    // e.g. 10 is 00...01010, and we need 3 (floor of log2(10))
    // so, it is total_length - (total_length-4) + 1
    // cout<<floor_log2<<"\n";
    return (1ll<<(floor_log2+1ll))-1ll;                             // 2*(floor(log2 n)+1)-1
}

bool isOne(ll x, ll n) {     // is position 'x' a one?
    if (n<2) return n;
    ll num = num_positions(n);                              // not setting this num to ll gives a wrong result!
                                                            // 903316762502 354723010040 354723105411
    if (x==num/2) return (n%2);
    else if(x>num/2) return isOne(x-num/2-1ll,n/2);
    else return isOne(x,n/2);
}

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin>>n>>l>>r;           // note: 2^50 >~ 10^15 [by: 2^10 = 1024 ~ 10^3]
                            // so use ll (can handle ~ 10^18)
    int cnt=0;
    for (ll i=l; i<=r; i++) {
        bool x = isOne(i-1,n);        // 0-indexing
        // cout<<x<<' ';
        cnt+=x;
    }
    // cout<<'\n';
    cout<<cnt<<"\n";
    
}
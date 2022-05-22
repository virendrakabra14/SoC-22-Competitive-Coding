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

int memo[10000]={0};    // some max no. taken
                        // initialized all to 0s

int fibM(int n) {
    if(memo[n]!=0) return memo[n];      // check in the memo
    else {
        memo[n] = fibM(n-1)+fibM(n-2);    // if not present, then make entry in the memo
        return memo[n];
    }
}

int fibT(int n) {
    int table[n+1];
    table[0]=table[1]=1;
    for (int i=2; i<n+1; i++) {
        table[i]=table[i-1]+table[i-2];     // for fib, no "table" required as such; can just do with 2 vars too
    }
    return table[n];
}


int main() {

    int n; cin>>n;

    memo[0]=memo[1]=1;      // 1,1,2,3,5,8,...
    
    cout<<fibM(n)<<'\t'<<fibT(n);    
    
}
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

ull pow1(int x, int n) {
    if(n==0) return 1;
    else {
        ull temp=pow1(x,n/2);
        if(n%2==0) return temp*temp;
        else return temp*temp*x;
    }
}

/*
For the iterative solution:
Think in terms of binary representation of n (i.e., exponent).
Consider x^13, where 13=1101_2, so, x^13 = x * x^4 * x^8.
    For every position in the binary representation (read it from the right),
    current power is squared (e.g., x -> x^2 -> x^4 ...),
    and whenever the bit is set (i.e., =1), then the current power is multiplied
*/

ull pow1_iter(int x, int n) {
    ull result=1;
    ull power=x;
    int m=n;
    while(m>0) {
        if(m%2==0) {
            power*=power;
            m/=2;           // effect same as a bit shift (right-shift)
        }
        else {
            result*=power;
            m-=1;
        }
    }
    return result;
}

int main() {

    int x,n; cin>>x>>n;
    cout<<pow1(x,n)<<'\n';
    cout<<pow1_iter(x,n)<<'\n';

    ull pow2;
    cout<<typeid(pow2).name()<<' '<<typeid(pow2*x).name()<<"\n";

}
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

vi a;

int merge(vi& a1, vi& a2, vi& a) {
    int i=0, j=0;
    int inv=0;
    while(i<a1.size() || j<a2.size()) {
        if(i>=a1.size()) {
            for (; j<a2.size(); j++) {
                a[i+j]=a2[j];
            }
            break;
        }
        else if(j>=a2.size()) {
            for(; i<a1.size(); i++) {
                a[i+j]=a1[i];
            }
            break;
        }
        else {
            if(a1[i]>a2[j]) {
                inv += a1.size()-i;
                a[i+j]=a2[j];
                j++;
            }
            else {
                a[i+j]=a1[i];
                i++;
            }
        }
    }
    return inv;
}

int count_inv(vi& a) {
    
    if(a.size()==1) return 0;

    int mid=a.size()/2;
    vi a1(a.begin(),a.begin()+mid);     // mid not taken here
                                        // note: if mid taken in first and not in second, 
                                        // then leads to infinite recursion in, e.g., a.size()==2 case.
    vi a2(a.begin()+mid,a.end());

    int n1=count_inv(a1);
    int n2=count_inv(a2);

    return n1+n2+merge(a1,a2,a);

}

int main() {
    
    int n; cin>>n;
    a.resize(n);
    
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }

    cout<<count_inv(a);

}
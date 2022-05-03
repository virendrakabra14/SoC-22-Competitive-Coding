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

int solve(int* a, int n) {

    int l=0, r=n-1;
    int mid=l+(r-l)/2;

    while(l<=r) {

        // cout<<l<<' '<<r<<' '<<mid<<"\n";

        if(l==r) {return l;}
        
        mid=l+(r-l)/2;
        
        if(a[mid]>a[mid+1]) {return mid+1;}           // since l<r if this is executed, so mid<n-1 always...
        if(mid>0 && a[mid-1]>a[mid]) {return mid;}

        // e.g. 11,12,2,3
        // say mid is 1, then a[mid]=12 is > a[r], and min is in right half √
        if(a[mid]<a[r]) r=mid-1;                    // compare with last element in this subarray
        else if(a[mid]>a[r]) l=mid+1;

    }

    return mid;

}


int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    // ios_base::sync_with_stdio(false); cin.tie(0);

    // int a[] = {1,2,3,4,5,6};
    int a[] = {11,12,13,2,3,4,5};
    cout << solve(a,sizeof(a)/sizeof(int)) << "\n";

    // int x; cin>>x;

    
}
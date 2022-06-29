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

void binSearch(int* a, int n, int target) {

    // cout<<sizeof(int*)<<"\n";       // 4 or 8 bytes
    // cout<<sizeof(a)/sizeof(int)<<"\n";

    int l=0, r=n-1;     // note that sizeof(a)/sizeof(int) won't work here,
                        // as 'a' is just a pointer
    int mid;

    while(l<=r) {
        cout<<l<<' '<<r<<"\n";      // to see the search range
        /*
            0 6
            4 6
            6 6 (because it is [mid+1,r])
        */
        if(l==r) {
            if(a[l]==target) cout<<l<<"\n";
            else cout<<"-1";
            return;
        }
        mid=l+(r-l)/2;      // NOT (l+r)/2 -- may cause overflow (bcoz l+r is calculated first)
        if(a[mid]==target) {cout<<mid<<"\n"; return;}
        else if(a[mid]>target) {r=mid-1;}       // search in left half
        else if(a[mid]<target) {l=mid+1;}       // search in right half
                                // note that mid+1 being out of array bounds won't be a problem here,
                                // because r is always <n, so l<=r condition would become false then.
    }

    cout<<"-1\n";

}

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // precalc();
    
    // int t; cin>>t;
    // while(t--) solve();
    
    int a[] = {2,4,5,7,9,100,2303};
    // int a[] = {0,1};

    int target=2303;

    binSearch(a,sizeof(a)/sizeof(int),target);
    
}
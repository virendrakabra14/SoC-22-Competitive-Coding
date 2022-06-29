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


// exchange
void exch (int& a, int& b) {      // passed by reference
    int temp = a;
    a = b;
    b = temp;
}

// figure in doc
int partition (int* a, int p, int r) {
    int x = a[r];       // pivot
    int i = p-1;
    for (int j=p; j<r; j++) {
        if (a[j]<=x) {
            i++;                    // note that i<j always (see figure in doc)
            exch(a[i],a[j]);        // if 'smaller than x' value in RHS, then bring it to LHS (swap)
        }
    }
    exch(a[i+1],a[r]);              // finally, bring pivot to its correct location
    return i+1;                     // the place to partition
}

void QuickSort (int* a, int p, int r) {
    if (p<r) {
        int q = partition(a,p,r);
        QuickSort(a,p,q-1);     // recurse on smaller problems
        QuickSort(a,q+1,r);     // pivot is at its correct location, so 'q' not included in either recursive call
    }
}

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0);

    int array[] = {2,3,4,3,2,1,3,56,6};
    int n = sizeof(array)/sizeof(int);

    QuickSort(array,0,n-1);
    
    
}
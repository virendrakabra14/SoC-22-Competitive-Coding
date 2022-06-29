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

int binSearch(int* a, int n, int target) {

    int l=0, r=n-1;

    while(l<=r) {
        if(l==r) {
            if(a[l]==target) return l;
            else return -1;
            break;
        }
        int mid=l+(r-l)/2;
        if(a[mid]==target) {return mid; break;}
        else if(a[mid]>target) {r=mid-1;}
        else if(a[mid]<target) {l=mid+1;}
    }

}

int occur(int* a, int n, int x) {

    int first = binSearch(a,n,x);
    
    if(first==-1) return 0;
    
    int last=first;
    int z=first;
    
    while(z!=-1) {
        // cout<<z<<' ';
        if(first==0) break;
        z=binSearch(a,first,x);
        if(z!=-1) first=z;      // if an earlier occurrence found, update first
    }
    
    z=last;
    while (z!=-1) {
        // cout<<z<<' ';
        if(last==n-1) break;        // since we are using address of a[last+1], so need to check this
        z=binSearch(&a[last+1],n-last-1,x);
        if(z!=-1) last+=(z+1);      // if a later occurrence found, update last
                                    // note that z is an indexing into array starting at position last+1, so update accordingly
    }
    
    return last-first+1;

}


int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int a[] = {2,4,4,7,7,7,8,10,10,12};        // sorted
    int min_elem = *min_element(a,a+sizeof(a)/sizeof(int));
    int max_elem = *max_element(a,a+sizeof(a)/sizeof(int));

    for (int i=min_elem-1; i<=max_elem+1; i++) {
        cout<<i<<'\t'<<occur(a,sizeof(a)/sizeof(int),i)<<"\n";
    }

    
}
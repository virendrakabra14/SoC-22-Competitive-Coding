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

void solve(int* a, int n, int numP) {
    
    int tot=0;
    for (int i=0; i<n; i++) {
        tot+=a[i];
    }

    int l=0, r=tot;         // could just use r=INT_MAX, instead of computing tot
    int mid = l+(r-l)/2;
    
    while(l<=r) {
        cout<<l<<'\t'<<mid<<'\t'<<r<<"\n";      // can see O(log(tot)) iterations
        if(l==r) {cout<<l<<"\n"; return;}
        mid=l+(r-l)/2;
        // try mid
        int index=0;        // index into a, to know how many walls covered
        for (int i=0; i<numP; i++) {
            int sum=0;
            while(sum+a[index]<=mid && index<n) {       // sum+a[index] <= mid, as no painter should take time >mid
                sum+=a[index];
                index++;
            }
        }
        if(index>=n) {r=mid-1;}     // achieved at mid √, so move to left half (we need to "minimize" the maximum time taken)
        else {l=mid+1;}             // not possible, so search in right
    }

    cout<<mid<<"\n";

}

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // int a[] = {40,20,10,30};
    int a[] = {10, 20, 60, 50, 30, 40};
    // int numP = 2;
    int numP = 3;
    solve(a,sizeof(a)/sizeof(int),numP);
    
}
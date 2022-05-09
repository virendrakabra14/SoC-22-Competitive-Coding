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

void solve() {
    
}

void precalc() {
    
}

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // pracC:73

    int n; cin>>n; int m; cin>>m;
    int a[200005];
    int nums[200005];

    int x;
    for (int i=0; i<n; i++) {
        cin>>x;
        nums[i]=x-1;
        a[x-1]=i;     // fill positions
    }

    int out=0;
    for (int i=0; i<n-1; i++) {
        if(a[i]>a[i+1]) out++;
    }

    // cout<<out+1<<"\n";
    out++;

    int y;
    for (int i=0; i<m; i++) {
        cin>>x>>y;
        x--;y--;
        // cout<<nums[x]<<' '<<nums[y]<<"\n";

        if(abs(nums[x]-nums[y])==1) {

            if(nums[x]<nums[y]) {
                if(a[nums[x]]>a[nums[y]]) out--;
                else out++;
                if(nums[x]>0 && a[nums[x]]>a[nums[x]-1] && a[nums[y]]<a[nums[x]-1]) out++;
                if(nums[x]>0 && a[nums[x]]<a[nums[x]-1] && a[nums[y]]>a[nums[x]-1]) out--;
                if(nums[y]+1<n && a[nums[y]]>a[nums[y]+1] && a[nums[x]]<a[nums[y]+1]) out--;
                if(nums[y]+1<n && a[nums[y]]<a[nums[y]+1] && a[nums[x]]>a[nums[y]+1]) out++;
            }
            else {
                if(a[nums[y]]>a[nums[x]]) out--;
                else out++;
                if(nums[y]>0 && a[nums[y]]>a[nums[y]-1] && a[nums[x]]<a[nums[y]-1]) out++;
                if(nums[y]>0 && a[nums[y]]<a[nums[y]-1] && a[nums[x]]>a[nums[y]-1]) out--;
                if(nums[x]+1<n && a[nums[x]]>a[nums[x]+1] && a[nums[y]]<a[nums[x]+1]) out--;
                if(nums[x]+1<n && a[nums[x]]<a[nums[x]+1] && a[nums[y]]>a[nums[x]+1]) out++;
            }

        }

        else if (nums[x]==nums[y]) {}

        else {

            // just check with adjacent ones...
        

            if(nums[x]+1<n && a[nums[x]]>a[nums[x]+1] && a[nums[y]]<a[nums[x]+1]) out--;
            if(nums[x]+1<n && a[nums[x]]<a[nums[x]+1] && a[nums[y]]>a[nums[x]+1]) out++;
            if(nums[x]>0 && a[nums[x]]>a[nums[x]-1] && a[nums[y]]<a[nums[x]-1]) out++;
            if(nums[x]>0 && a[nums[x]]<a[nums[x]-1] && a[nums[y]]>a[nums[x]-1]) out--;
            if(nums[y]+1<n && a[nums[y]]>a[nums[y]+1] && a[nums[x]]<a[nums[y]+1]) out--;
            if(nums[y]+1<n && a[nums[y]]<a[nums[y]+1] && a[nums[x]]>a[nums[y]+1]) out++;
            if(nums[y]>0 && a[nums[y]]>a[nums[y]-1] && a[nums[x]]<a[nums[y]-1]) out++;
            if(nums[y]>0 && a[nums[y]]<a[nums[y]-1] && a[nums[x]]>a[nums[y]-1]) out--;
        
        }
        cout<<out<<"\n";

        swap(a[nums[x]],a[nums[y]]);
        swap(nums[x],nums[y]);
        
    }
    
}
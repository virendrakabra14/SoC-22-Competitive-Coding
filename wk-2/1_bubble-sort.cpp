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

void swap1(int& a, int& b) {
    int temp=a;
    a=b;
    b=temp;
}

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0);

    int array[] = {2,3,4,3,2,1,3,56,6};
    int n = sizeof(array)/sizeof(int);

    int inv=0;      // number of inversions in array

    for (int i=0; i<n; i++) {
        for (int j = 0; j<n-1; j++) {
            if (array[j] > array[j+1]) {
                swap1(array[j],array[j+1]);     // in-built swap() too
                inv++;
            }
        }
    }

    for (int i=0; i<n; i++) {
        cout<<array[i]<<' ';
    }
    cout<<"\n"<<inv<<"\n";
    // inv = 1+2+4+2+1+1
    // e.g. for first '2', there's a '1' ahead of it, etc...
    
}
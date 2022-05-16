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

int tiles_placed=0;
vvi a;

int checkQuadrant(int k, int x1, int y1, int x, int y) {
    int xmid=x1+(1<<k)/2-1;
    int ymid=y1+(1<<k)/2-1;
    if(x>xmid && y>ymid) return 3;                  // bottom-right
    else if(x<=xmid && y>ymid) return 2;            // bottom-left
    else if(x>xmid && y<=ymid) return 1;            // top-right
    else return 0;                                  // top-left
}

int cnt=0;
void placeTile (int quad, int x1, int y1) {
    cnt++;
    if(quad==0) {               // hole in top-left
        a[x1+1][y1]=cnt;        // x horizontal (left to right), y vertical (top to bottom)
        a[x1+1][y1+1]=cnt;
        a[x1][y1+1]=cnt;
    }
    else if (quad==1) {         // top-right
        a[x1][y1]=cnt;
        a[y1+1][x1]=cnt;
        a[y1+1][x1+1]=cnt;
    }
    else if (quad==2) {         // bottom-left
        a[y1][x1]=cnt;
        a[y1][x1+1]=cnt;
        a[x1+1][y1+1]=cnt;
    }
    else {
        a[x1][y1]=cnt;
        a[x1+1][y1]=cnt;
        a[x1][y1+1]=cnt;
    }
}

void tile(int k, int x1, int y1, int x, int y) {
    int quad=checkQuadrant(k,x1,y1,x,y);
    if (k==1) {
        placeTile(quad,x1,y1);
        return;
    }
    else {
        placeTile(quad,x1+1<<(k-1)-1,y1+1<<(k-1)-1);        // want missing tile in same quadrant that has hole
                                                            // (effect ~ to hole in other quadrants)
        if(quad==0) {
            tile(k-1,x1,y1,x,y);                                            // top-left (contains hole)
            tile(k-1,x1+(1<<(k-1)),y1,x1+(1<<(k-1)),y1+(1<<(k-1)-1));       // tile top-right
            tile(k-1,x1,y1+(1<<(k-1)),x1+(1<<(k-1)-1),y1+(1<<(k-1)));       // tile bottom-left
            tile(k-1,x1+(1<<(k-1)),y1+(1<<(k-1)),x1+(1<<(k-1)),y1+(1<<(k-1)));  // bottom-right
        }
        if(quad==1) {
            tile(k-1,x1,y1,x1+(1<<(k-1)-1),y1+(1<<(k-1)-1));
            tile(k-1,x1+(1<<(k-1)),y1,x,y);                                 // tile top-right (contains hole)
            tile(k-1,x1,y1+(1<<(k-1)),x1+(1<<(k-1)-1),y1+(1<<(k-1)));       // tile bottom-left
            tile(k-1,x1+(1<<(k-1)),y1+(1<<(k-1)),x1+(1<<(k-1)),y1+(1<<(k-1)));  // bottom-right
        }
        if(quad==2) {
            tile(k-1,x1,y1,x1+(1<<(k-1)-1),y1+(1<<(k-1)-1));
            tile(k-1,x1+(1<<(k-1)),y1,x1+(1<<(k-1)),y1+(1<<(k-1)-1));       // tile top-right
            tile(k-1,x1,y1+(1<<(k-1)),x,y);                                 // tile bottom-left (contains hole)
            tile(k-1,x1+(1<<(k-1)),y1+(1<<(k-1)),x1+(1<<(k-1)),y1+(1<<(k-1)));  // bottom-right
        }
        if(quad==3) {
            tile(k-1,x1,y1,x1+(1<<(k-1)-1),y1+(1<<(k-1)-1));
            tile(k-1,x1+(1<<(k-1)),y1,x1+(1<<(k-1)),y1+(1<<(k-1)-1));       // tile top-right
            tile(k-1,x1,y1+(1<<(k-1)),x1+(1<<(k-1)-1),y1+(1<<(k-1)));       // tile bottom-left
            tile(k-1,x1+(1<<(k-1)),y1+(1<<(k-1)),x,y);                      // bottom-right (contains hole)
        }
    }
}

int main() {
    int k; cin>>k;

    a.clear(); a.resize(1<<k,vi(1<<k,-5));
    
    // coordinates of hole
    // (x,y) inside this 2^k x 2^k tile
    int x,y;
    cin>>x>>y;

    a[x][y]=-1;

    tile(k,0,0,x,y);

    for (int i=0; i<(1<<k); i++) {
        for (int j=0; j<(1<<k); j++) {
            cout<<a[j][i]<<'\t';
        }
        cout<<"\n";
    }

}
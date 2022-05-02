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

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;

/*
    M: return a vector of permutations.
    e.g., abcde: then a recursive call would return vector{cde,ced,dce,dec,ecd,edc}.
*/

vector<string> calc(string s) {
    if(s.length()==1) {
        vs v;
        v.push_back(s);
        return v;
    }
    unordered_set<char> s1;
    vs v11;
    for (int i=0; i<s.length(); i++) {
        if(s1.find(s[i])==s1.end()) {
            s1.insert(s[i]);
            string s2=s;
            char temp; temp=s2[0]; s2[0]=s[i]; s2[i]=temp;
            string s3 = s2.substr(1,s2.length()-1);
            vs v=calc(s3);
            for (int i=0; i<v.size(); i++) {
                string s4{s2[0]};
                v11.pb(s4+v[i]);
            }
        }
    }
    return v11;
}

void solve() {
    string s; cin>>s;
    vs v=calc(s);
    cout<<v.size()<<"\n";
    sort(v.begin(),v.end());
    for (int i=0; i<v.size(); i++) {
        cout<<v[i]<<"\n";
    }
}

void precalc() {
    
}

int main() {
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // precalc()
    
    // int t; cin>>t;
    // while(t--) solve();
    solve();
    
}
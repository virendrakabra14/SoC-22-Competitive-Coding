#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef pair<int,int> pii;
typedef map<int,int> mii;

int main() {

    pair<int,char> p(1,'a');
    cout<<p.first<<' '<<p.second<<"\n";

    p = make_pair(1,'a');
    p = {1,'a'};

    map<int,int> m1;
    m1.insert(pii(1,10));
    m1.insert(pii(3,20));
    m1.insert(pii(-1,100));
    m1[-10] = 1000;
    m1[-10] = 1000;     // only once...
    // use multimap if many elements with same key are required.

    // erase
    m1.erase(1);        // key

    for (mii::iterator it=m1.begin(); it!=m1.end(); it++) {
        cout<<it->first<<'\t'<<it->second<<"\n";
    }
    // easier:
    // for (auto i : m1) {
    //     cout << i.first << '\t' << i.second << "\n"; 
    // }

    // find (arg=key)
    // returns iterator to element if found, else iterator to map.end() [i.e., position AFTER end of map]
    cout << (m1.find(3)!=m1.end() ? "found" : "not found") << "\n";
    cout << (m1.count(3) ? "found" : "not found") << "\n";      // count!=0, then...
    cout << m1[3] << "\n";

    // map: ordered

    // use unordered_map when order isn't required
    // fast search, insert, delete operations
    // ~ hash table
    // unordered_map<int,int>

    // example
    // given an array and a target sum, is there a pair of integers that add up to the target sum

    vector<int> v{1,2,5,3,4,-1,10};
    int target=8;

    // M1: all pairs O(n^2)
    for (int i=0; i<v.size(); i++) {
        bool done=false;
        for (int j=0; j<v.size(); j++) {
            if (v[i]+v[j] == target) {cout << v[i] << ' ' << v[j] << "\n"; done=true;}
        }
        if (done) {break;}
    }

    //M2: search for complement (target-v[i])
    // need a data structure that has small lookup time
    // not a vector or map, but an unordered_map
    // but keys NOT required, so unordered_set works!

    unordered_set<int> set1;
    for (int i=0; i<v.size(); i++) {
        if (set1.find(target-v[i])!=set1.end()) {
            cout<<"M2: found\n";
            break;
        }
        else {
            set1.insert(v[i]);
        }
    }

    // lower_bound
    // upper_bound
    // https://www.geeksforgeeks.org/set-in-cpp-stl/

    set<int> set2;
    set2.insert(1);
    set2.insert(1);
    set2.insert(2);
    for (auto i: set2) cout<<i<<" ";
    cout<<"\n";


}
#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;

// #include <vector>

int main() {

    ios_base::sync_with_stdio(false); cin.tie(0);

    vi v;           // vector<int> v

    int n=10;
    vi v1(n);       // len n

    int a=0;
    vi v2(n,a);     // len n, all initialized to 'a'

    vi v3 {1,2,3,4};
    vi v4(v3.begin()+1,v3.end()-1);   // 2,3 in v4 (everything from 1st parameter, and BEFORE 2nd parameter)

    cout << "size of v:\t" << v.size() << "\n";

    v.push_back(1);     // argument must be same as type of vector
    v.pb(2);
    v.pb(3);                    // 1 2 3
    v.insert(v.begin()+1,4);    // 1 4 2 3
    v.insert(v.begin()+2, {5,6});   // 1 4 5 6 2 3
    v.erase(v.begin()+3);       // 1 4 5 2 3
    v.pop_back();               // 1 4 5 2

    cout << "vector v:\t";
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << "\n";

    cout << "vector v2:\t";
    for (auto elem : v2) {
        cout << elem << ' ';
    }
    cout << "\n";

    v1 = v;     // assigned

    cout << "vector v4:\t";
    // type of it is vector<int>::iterator
    for (auto it=v4.begin(); it!=v4.end(); it++) {      // v1.end() points to element *after* the end of v1
        cout << *it << ' ';     // dereference
    }
    cout << "\n";

    sort(v.begin(), v.end());       // #include <algorithm>
                                    // can also use customized compare function
    reverse(v.begin(),v.end());
    cout << "vector v after sorting:\t";
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << "\n";

    // to sort an array
    int arr[] = {3,2,1,5,4};
    sort(arr,arr+sizeof(arr)/sizeof(int));      // sort(arr,arr+n)
                                        // NOTE: don't use sizeof() when passing an array as a pointer in a function
                                        // because then it'll be size of just a pointer
    cout << "array after sorting:\t";
    for (int i=0; i<sizeof(arr)/sizeof(int); i++) {
        cout << arr[i] << ' ';
    }
    cout << "\n";

    // 2d vector
    vvi v2d(3,vi(7,0));
    for (int i=0; i<v2d.size(); i++) {
        for (int j=0; j<v2d[0].size(); j++) {
            cout<<v2d[i][j];
        }
        cout<<"\n";
    }

    
}
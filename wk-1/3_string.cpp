#include <bits/stdc++.h>
using namespace std;

#define pb push_back

// #include <string>

int main() {

    string s="abcd";
    s.push_back('e');       // '' for characters, "" for strings

    // just cout<<s; works (like char array)

    cout << "string s:\t";
    for (int i=0; i<s.length(); i++) {      // length()
        cout << s[i];       // indexing
    }
    cout << "\n";

    s.pop_back();

    
    char * cptr = new char[s.length()+1];       // +1 for '\0'
    // #include <cstring>
    strcpy(cptr,s.c_str());
    cout << "char array:\t" << cptr << "\n";

    string s1(cptr);    // initialize by char array
    // also, s1=s;

    // same iterators
    cout << "string s1:\t";
    for (string::iterator it=s1.begin(); it!=s1.end(); it++) {
        cout << *it;
    }
    cout << "\n";

    string s2="qwerty";
    sort(s2.begin(),s2.end());      // lexicographically
    reverse(s2.begin(),s2.end());
    cout << "s2:\t" << s2 << "\n";

    // debug: fn+f5
    int x;
    cin>>x;


}
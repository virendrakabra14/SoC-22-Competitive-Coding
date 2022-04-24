#include <bits/stdc++.h>
using namespace std;

#define pb push_back

// #include <stack>
// #include <queue>
// #include <deque>
// #include <priority_queue>

// struct my_struct {
//     int x;
// };
struct comp{
    bool operator() (int s1, int s2) {       // overload operator()
        return s1>s2;
    }
};

int main() {

    stack<int> st;
    for (int i=0; i<10; i++) {
        st.push(i);
    }

    for (int i=0; i<5; i++) {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << "\n";

    cout << st.size() << "\n";

    while(!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    // at the end of this loop, condition is true => st.empty() is true
    cout<<"\n";

    // -- queue

    queue<int> q;
    for (int i=0; i<10; i++) {
        q.push(i);
    }

    for (int i=0; i<5; i++) {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << "\n";

    cout << q.empty() << ' ' << q.size() << "\n";

    // deque

    deque<int> dq;

    for (int i=0; i<5; i++) {
        dq.push_back(i);
    }
    for (int i=0; i<5; i++) {
        dq.push_front(i+5);
    }
    // 9 8 7 6 5 0 1 2 3 4

    int n = dq.size();
    for (int i=0; i<n/2; i++) {
        cout << dq.back() << ' ';
        dq.pop_back();
    }
    cout<<"\n";

    cout << dq.empty() << "\n";


    priority_queue<int> pq;     // max heap
    for (int i=0; i<10; i++) {
        pq.push(i);
    }
    cout<<"pq.top():\t"<<pq.top()<<"\n";

    priority_queue<int,vector<int>,greater<int>> pq1;       // min heap
    for (int i=10; i>0; i--) {
        pq1.push(i);
    }
    cout<<"pq1.top():\t"<<pq1.top()<<"\n";


    // custom compare function
    priority_queue<int,vector<int>,comp> pq2;               // max heap
    for (int i=0; i<10; i++) {
        pq2.push(i);
    }
    cout<<"pq2.top():\t"<<pq2.top()<<"\n";



}
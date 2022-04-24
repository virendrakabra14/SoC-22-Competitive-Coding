#include <bits/stdc++.h>
using namespace std;

int main() {

    int a = 5, b = 9;   // a = 5(00000101), b = 9(00001001) // 32 bits (int)
    cout << (a^b) << "\n";   // 00001100      // XOR
    cout <<(~a) << "\n";       // 11...1010     // 2's complement 111...1 010
    // &, |

    // https://www.geeksforgeeks.org/c-bitset-and-its-application/

    bitset<10> bset1;
    bitset<10> bset2(20);
    bitset<10> bset3(string("1100"));

    // 0000000000
    // 0000010100
    // 0000001100

    bitset<8> set8; // 00000000

    set8[1] = 1; // 00000010
    set8[4] = set8[1]; // 00010010
    cout << set8 << endl;
  
    // count function returns number of set bits in bitset
    int x1 = set8.count();
  
    // any() function returns true, if atleast 1 bit is set
    // none() function returns true, if none of the bit is set
  
    // set() sets all bits
    cout << set8.set() << endl;
  
    // reset function makes all bits 0
    cout << set8.reset() << endl;
  
    // flip function flips all bits
    cout << set8.flip(2) << endl;
    cout << set8.flip() << endl;        // set8[..]=1
  
    // Converting decimal number to binary by using bitset
    int num = 100;
    cout << num << bitset<8>(num);
    
}
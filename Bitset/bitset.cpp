#include <bits/stdc++.h>
using namespace std;

int main() {
    
    // Default Initialization
    bitset<5> bnum(18);
    cout << bnum << endl;

    bitset<5> bs2("10011");

    cout << bs2 << endl;

    // 18 = (10010)
    bitset<5> bs(18);
    
    // Check 3rd bit from right
    cout << bs[2] << endl;
    
    // Check 5th bit
    cout << bs.test(4)<<endl;
    
    bs=18;
    // Set 1st bit
    bs.set(0);
    cout << bs << endl;
    
    // Reset 2nd bit 
    bs.reset(1);
    cout << bs << endl;
    
    // Flip 5th bit
    bs.flip(4);
    cout << bs <<endl;

    // 18 = (10010)
    bitset<5> bs1(18);
    
    // 2 = (00010)
    bs2=2;
    
    // AND Operator 
    cout << (bs1 & bs2) << endl;
    
    // OR Operator
    cout << (bs1 | bs2) << endl;
    
    // XOR operator
    cout << (bs1 ^ bs2);
    return 0;
}

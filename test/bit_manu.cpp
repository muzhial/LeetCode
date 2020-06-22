#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

const int MIN = std::numeric_limits<int>::min();
const int MAX = std::numeric_limits<int>::max();

int shift() {
    int vi = 1;
    unsigned int uvi = 1;
    int vii = 255;
    cout << (vi >> 2) << endl;    // 0
    cout << (uvi << 31) << endl;  // 2147483648
    cout << (vi << 30) << endl;   // 1073741824
    cout << (vi << 31) << endl;   // -2147483648
    cout << (vi << 34) << endl;   // 4 warning: left shift count >= width of type [enabled by default]

    cout << (vii << 25) << endl;  // -33554432
    cout << (-1 << 1) << endl;    // -2

    cout << (-1 >> 1) << endl;    // -1

    return 0;
}

int main() {
    int vi = 5;   // 00000000 00000000 00000000 00000101
    int vii = 3;  // 00000000 00000000 00000000 00000011
    int andi = vi & vii;  // 00000000 00000000 00000000 00000001
    int ori = vi | vii;   // 00000000 00000000 00000000 00000111
    int xori = vi ^ vii;  // 00000000 00000000 00000000 00000110
    int viii = 1;
    // 00000000 00000000 00000000 00000001
    // 11111111 11111111 11111111 11111110 -> -2^31 + 2^31 - 1 - 1 = -2
    int noti = ~viii;     // 11111111 11111111 11111111 11111110

    int viv = -1;         // 11111111 11111111 11111111 11111111
    int vv = -2;          // 11111111 11111111 11111111 11111110
    int andii = viv & vv; // -2
    int xorii = viv ^ vv; // 1
    // cout << xorii << endl;

    shift();

    cout << (int)std::abs(-2147483648) << endl;        // -2147483648
    cout << (long long)std::abs(-2147483648) << endl;  // 2147483648
    return 0;
}
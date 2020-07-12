#include "../common.hpp"
using namespace std;

/***************
****************/
// 最大公约数(欧几里得算法)
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 更相减损术
int gcd_ii(int a, int b) {
    if (a == b) {
        return a;
    }
    if (a < b) {
        return gcd_ii(b - a, a);
    } else {
        return gcd_ii(a - b, b);
    }
}

// 进一步优化用移位和更相减法
int gcd_iii(int a, int b) {
    if (a == b) {
        return a;
    }
    if (a < b) {
        return gcd_iii(b, a);
    } else {
        // a, b 皆偶
        if (!(a&1) && !(b&1)) {
            return gcd_iii(a >> 1, b >> 1) << 2;
        } else if (!(a&1) && (b&1)) {
            return gcd_iii(a >> 1, b);
        } else if ((a&1) && !(b&1)) {
            return gcd_iii(a, b >> 1);
        } else {
            return gcd_iii(b, a - b);
        }
    }
}


// 最小公倍数
// 两数的乘积除以最大公约数
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int a = 4;
    cout << (~a) << endl;  // -2
    cout << !(a & 1) << endl;
    cout << (!a & 1) << endl;

    return 0;
}
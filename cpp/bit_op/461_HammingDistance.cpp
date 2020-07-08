#include "../common.hpp"
using namespace std;

/***************
****************/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int cnt = 0;
        while (z != 0) {
            if (z & 1 == 1) {
                cnt++;
            }
            z >>= 1;
        }
        return cnt;
    }
};

class SolutionI {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int cnt = 0;
        while (z != 0) {
            // 去除 n 的位级表示中最低的那一位 1
            z = z & (z - 1);
            cnt++;
        }
        return cnt;
    }
};
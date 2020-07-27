#include "../common.hpp"
using std::vector;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int MIN = std::numeric_limits<int>::min();
        int MAX = std::numeric_limits<int>::max();
        int n1 = nums1.size();
        int n2 = nums2.size();
        // 使 nums1 长度不大于 nums2 长度
        if (n1 > n2) {
            // leetcode heap-buffer-overflow
            // std::swap(nums1, nums2);
            return findMedianSortedArrays(nums2, nums1);
        }
        int k = (n1 + n2 + 1) / 2;
        int l = 0;
        int r = n1;
        while (l < r) {
            int m1 = l + (r - l) / 2;
            int m2 = k - m1;
            if (nums1[m1] < nums2[m2 - 1]) {
                l = m1 + 1;
            } else {
                r = m1;
            }
        }
        int m1 = l;
        int m2 = k - l;
        int c1 = std::max(m1 <= 0 ? MIN : nums1[m1 - 1],
                          m2 <= 0 ? MIN : nums2[m2 - 1]);
        
        // odd
        if ((n1 + n2) % 2 == 1) {
            return c1;
        }
        // even
        int c2 = std::min(m1 >= n1 ? MAX : nums1[m1],
                          m2 >= n2 ? MAX : nums2[m2]);
        return (c1 + c2) / 2.0;
    }
};


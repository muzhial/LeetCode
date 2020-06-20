#include "../common.hpp"
using namespace std;
using std::vector;

/***************
****************/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(LeftBound(nums, target));
        res.push_back(RightBound(nums, target));
        return res;
    }
    int LeftBound(vector<int>& A, int target) {
        int left = 0;
        int right = A.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] < target) {
                left = mid + 1;
            } else if (A[mid] > target) {
                right = mid - 1;
            } else if (A[mid] == target) {
                right = mid - 1;
            }
        }
        if (left >= A.size() || A[left] != target) {
            return -1;
        }
        return left;
    }
    int RightBound(vector<int>& A, int target) {
        int left = 0;
        int right = A.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] < target) {
                left = mid + 1;
            } else if (A[mid] > target) {
                right = mid - 1;
            } else if (A[mid] == target) {
                left = mid + 1;
            }
        }
        if (right < 0 || A[right] != target) {
            return -1;
        }
        return right;
    }
};
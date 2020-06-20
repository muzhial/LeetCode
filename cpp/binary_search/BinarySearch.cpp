#include "../common.hpp"
using namespace std;
using std::vector;

/***************
****************/
// Method 1
// 左侧边界
int BinarySearchI(vector<int> &A, int target) {
    int start = 0;
    int end = A.size();
    int mid = 0;
    while(start + 1 < end) {
        mid = start + (end - start) / 2; // 防止溢出可能
        // mid = (start + end) / 2;      // 可能溢出
        if(target < A.at(mid)) {
            end = mid;
        }
        else if(target > A.at(mid)) {
            start = mid;
        }
        else if(target == A.at(mid)) {
            end = mid;
        }
    }

    if(target == A.at(start)) {
        return start;
    }
    if(target == A.at(end)) {
        return end;
    }
    return -1;
}

// Method 2
// 一般情况
int BinarySearchII(vector<int>& A, int target) {
    int left = 0;
    int right = A.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (A[mid] > target) {
            right = mid - 1;
        } else if (A[mid] < target) {
            left = mid + 1;
        } else if (A[mid] == target) {
            return mid;
        }
    }
    return -1;
}

int LeftBound(vector<int>& A, int target) {
    int left = 0;
    int right = A.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (A[mid] > target) {
            right = mid - 1;
        } else if (A[mid] < target) {
            left = mid + 1;
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
        if (A[mid] > target) {
            right = mid - 1;
        } else if (A[mid] < target) {
            left = mid + 1;
        } else if (A[mid] == target) {
            left = mid + 1;
        }
    }
    if (right < 0 || A[right] != target) {
        return -1;
    }
    return right;
}

# Binary Search

比 O(n) 更优的时间复杂度几乎只能是 O(logn) 的二分法。

## 基本框架

注意边界情况，考虑下述情况：

* target 比所有的都小
* target 比所有的都大
* target 在列
* target 不在列，在某两个数之间

### 第一种

[left, right]
```cpp
int BinarySearch(vector<int>& A, int target) {
    int left = 0;
    int right = A.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (A[mid] == target) {
            return mid;
        } else if (A[mid] < target) {
            left = mid + 1;
        } else if (A[mid] > target) {
            right = mid - 1;
        }
    }
    return -1;
}

// 左侧边界
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

// 右侧边界
int RightBound(vector<int>&A, int target) {
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
```

### 第二种

[left, right) --> 左侧边界
```cpp
int BinarySearch(vector<int>& A, int target) {
    int start = 0;
    int end = A.size();
    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (target < A[mid]) {
            end = mid;
        } else if (target > A[mid]) {
            start = mid;
        } else if (target == A[mid]) {
            end = mid;
        }
    }
    if (target == A[start]) {
        return start;
    }
    if (target == A[end]) {
        return end;
    }
    return -1;
}
```

# Q&A

1. Binary Search, recursion or while-loop?

`recursion` 需要额外耗费栈空间，当深度过大，会出现 *stack over flow*。两者时间复杂度一样，但 `recursion` 可能更耗时，因为空间的额外耗费一般会导致时间增加。

2. 二分法的使用条件？

需要优化一个 O(n) 的暴力算法；sorted array or rotated sorted array。


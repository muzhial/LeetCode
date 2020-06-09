#include <iostream>
#include <vector>
#include <string>

// first position
int BinarySearch(std::vector<int> &A, int target) {
    int start = 0;
    int end = A.size();
    int mid = 0;
    while(start + 1 < end) {
        mid = start + (end - start) / 2; // 防止溢出可能
        // mid = (start + end) / 2; // 可能溢出
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

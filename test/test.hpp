#ifndef TEST_HPP_
#define TEST_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <utility>
#include <algorithm>
#include <functional>

void PrintVector(std::vector<int>& v) {
    for (auto& i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void PrintVVector(std::vector<std::vector<int>>& v) {
    for (auto& i : v) {
        for (auto& ii : i) {
            std::cout << ii << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

#endif
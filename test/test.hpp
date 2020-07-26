#ifndef TEST_HPP_
#define TEST_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

void PrintVector(std::vector<int>& v) {
    for (auto& i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

#endif
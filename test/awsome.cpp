#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Default constructor" << std::endl;
    }
    Base(int cnt, int len): cnt_(cnt), len_(len) {
        std::cout << "Constructor with param" << std::endl;
    }
    Base(const Base& orig): cnt_(orig.cnt_), len_(orig.len_) {
        std::cout << "Copy constructor" << std::endl;
    }
    Base& operator=(const Base& rhs) {
        cnt_ = rhs.cnt_;
        len_ = rhs.len_;
        std::cout << "Copy-assignment constructor" << std::endl;

        return *this;
    }
    ~Base() {};
private:
    int cnt_;
    int len_;
};

void TestLambda() {
    int x = 11;
    int y = 13;

    auto fl = [&x, &y]() mutable -> void {
        x = 1;
        std::cout << x << " " << y << std::endl;
    };
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    std::cout << x << " " << y << std::endl;
    fl();
    std::cout << x << " " << y << std::endl;
}

int main() {
    // Base b = {1, 2};
    // Base b1;
    // b1 = b;

    TestLambda();

    return 0;
}
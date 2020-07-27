#include <iostream>
#include <vector>
#include <stack>
#include <limits>
#include <set>
using std::cout;
using std::endl;
using std::set;

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

/*
 * typename when template
**/
// template<typename T>
// void SelectionSort(std::vector<T>& arr)
// typedef typename std::vector<T>::size_type size_type;

void TestSet() {
    set<int> sv;
    sv.insert(3);
    sv.insert(3);
    sv.insert(4);

    for (auto& s : sv) {
        cout << s << " " << endl;
    }
}

void TestLonglong() {
    int a = 1;
    cout << (a << 31) << endl;
    long long i = (a << 30) * (a << 30);
    cout << i << endl;
    long long ii = (static_cast<long long>(a) << 30) * (a << 30);
    cout << ii << endl;
}

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
    TestSet();

    return 0;
}
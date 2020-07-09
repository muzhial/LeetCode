void swap_two_nums(int& a, int& b) {
    a = a ^ b;
    b = a ^ b;  // a
    a = a ^ b;
}
#include<iostream>
void example(int x) {
    if (x > 10) {
        std::cout << "x is greater than 10" << std::endl;
        return;
    } else if (x > 5) {
        std::cout << "x is greater than 5" << std::endl;
        return;
    } else if (x > 0) {
        std::cout << "x is greater than 0" << std::endl;
        return;
    } else {
        std::cout << "x is 0 or less" << std::endl;
        return;
    }
}

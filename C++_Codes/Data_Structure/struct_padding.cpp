#include <iostream>


/// @brief Disable structure padding
struct __attribute__((packed)) Example {
    char a;      // 1 byte
    int b;       // 4 bytes
    double c;    // 8 bytes
};

int main() {
    std::cout << sizeof(Example) << std::endl;
    return 0;
}

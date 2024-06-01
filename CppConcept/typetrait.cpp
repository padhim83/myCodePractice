#include <iostream>
#include <type_traits>

template <typename T, Typename U>

void checkType() {
    if (std::is_integral<T>::value) {
        std::cout << "T is an integral type\n";
    } else {
        std::cout << "T is not an integral type\n";
    }
}

int main() {
    checkType<int>();       // Output: T is an integral type
    checkType<float>();     // Output: T is not an integral type

    return 0;
}
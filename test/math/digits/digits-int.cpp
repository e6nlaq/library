#define LIBTEST
#include <e6nlaq/math/integer.hpp>
#include <iostream>

int main() {
    int cases;
    std::cin >> cases;

    while (cases--) {
        int N;
        std::cin >> N;

        std::cout << e6nlaq::digits(N) << std::endl;
    }

    return 0;
}
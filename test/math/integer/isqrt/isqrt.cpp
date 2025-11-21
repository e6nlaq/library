#define LIBTEST
#include <e6nlaq/math/integer.hpp>
#include <iostream>

int main() {
    int cases;
    std::cin >> cases;

    while (cases--) {
        long long N;
        std::cin >> N;

        std::cout << e6nlaq::isqrt(N) << std::endl;
    }

    return 0;
}
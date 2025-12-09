#define LIBTEST
#include <e6nlaq/math/integer.hpp>
#include <iostream>

int main() {
    int cases;
    std::cin >> cases;
    while (cases--) {
        unsigned long long x, n;
        std::cin >> x >> n;
        std::cout << e6nlaq::pow_ll(x, n) << '\n';
    }
    return 0;
}

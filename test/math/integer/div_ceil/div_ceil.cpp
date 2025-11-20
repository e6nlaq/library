#define LIBTEST
#include <e6nlaq/math/integer.hpp>
#include <iostream>

int main() {
    int cases;
    std::cin >> cases;
    while (cases--) {
        long long a, b;
        std::cin >> a >> b;
        std::cout << e6nlaq::div_ceil(a, b) << '\n';
    }
    return 0;
}

#define LIBTEST
#include <e6nlaq/math/integer.hpp>
#include <iostream>

int main() {
    int cases;
    std::cin >> cases;
    while (cases--) {
        long long x, m;
        std::cin >> x >> m;
        std::cout << e6nlaq::mmod(x, m) << '\n';
    }
    return 0;
}

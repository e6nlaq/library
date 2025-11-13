#define LIBTEST
#include <e6nlaq/math/integer.hpp>
#include <iostream>

int main() {
    int cases;
    std::cin >> cases;
    while (cases--) {
        long long n;
        std::cin >> n;
        std::cout << e6nlaq::fact(n) << '\n';
    }
    return 0;
}

#define PROBLEM "https://yukicoder.me/problems/no/2879"

#include "e6nlaq/imos.hpp"

#include <iostream>

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    e6nlaq::imos imos(A);

    while (Q--) {
        int L, R;
        std::cin >> L >> R;
        imos.add(L - 1, R, 1);
    }

    auto ans = imos.get();
    for (int i = 0; i < N; ++i) {
        std::cout << ans[i] % 2 << (i == N - 1 ? "\n" : " ");
    }

    return 0;
}
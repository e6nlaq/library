// @e6nlaq/library / (C) 2025 e6nlaq
// This file is a fork of AtCoder Library.

#ifndef E6NLAQ_INTERNAL_CSR_HPP
#define E6NLAQ_INTERNAL_CSR_HPP 1

#include <algorithm>
#include <utility>
#include <vector>

namespace e6nlaq {
namespace internal {

template <class E>
struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

}  // namespace internal

}  // namespace e6nlaq

#endif  // E6NLAQ_INTERNAL_CSR_HPP

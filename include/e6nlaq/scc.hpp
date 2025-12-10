// This file is a fork of AtCoder Library.

#ifndef E6NLAQ_SCC_HPP
#define E6NLAQ_SCC_HPP 1

#include <cassert>
#include <vector>

#include "internal/scc.hpp"

namespace e6nlaq {

struct scc_graph {
   public:
    scc_graph() : internal(0) {}
    explicit scc_graph(int n) : internal(n) {}

    void add_edge(int from, int to) {
        int n = internal.num_vertices();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.add_edge(from, to);
    }

    std::vector<std::vector<int>> scc() { return internal.scc(); }

   private:
    internal::scc_graph internal;
};

}  // namespace e6nlaq

#endif  // E6NLAQ_SCC_HPP

---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: include/e6nlaq/internal/csr.hpp
    title: include/e6nlaq/internal/csr.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: include/e6nlaq/all.hpp
    title: include/e6nlaq/all.hpp
  - icon: ':warning:'
    path: include/e6nlaq/scc.hpp
    title: include/e6nlaq/scc.hpp
  - icon: ':warning:'
    path: include/e6nlaq/twosat.hpp
    title: include/e6nlaq/twosat.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ include/e6nlaq/internal/scc.hpp: line 10: unable to process #include in #if\
    \ / #ifdef / #ifndef other than include guards\n"
  code: "// This file is a fork of AtCoder Library.\n\n#ifndef E6NLAQ_INTERNAL_SCC_HPP\n\
    #define E6NLAQ_INTERNAL_SCC_HPP 1\n\n#include <algorithm>\n#include <utility>\n\
    #include <vector>\n\n#include \"e6nlaq/internal/csr.hpp\"\n\nnamespace e6nlaq\
    \ {\nnamespace internal {\n\n// Reference:\n// R. Tarjan,\n// Depth-First Search\
    \ and Linear Graph Algorithms\nstruct scc_graph {\n   public:\n    explicit scc_graph(int\
    \ n) : _n(n) {}\n\n    int num_vertices() { return _n; }\n\n    void add_edge(int\
    \ from, int to) { edges.push_back({from, {to}}); }\n\n    // @return pair of (#\
    \ of scc, scc id)\n    std::pair<int, std::vector<int>> scc_ids() {\n        auto\
    \ g = csr<edge>(_n, edges);\n        int now_ord = 0, group_num = 0;\n       \
    \ std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);\n        visited.reserve(_n);\n\
    \        auto dfs = [&](auto self, int v) -> void {\n            low[v] = ord[v]\
    \ = now_ord++;\n            visited.push_back(v);\n            for (int i = g.start[v];\
    \ i < g.start[v + 1]; i++) {\n                auto to = g.elist[i].to;\n     \
    \           if (ord[to] == -1) {\n                    self(self, to);\n      \
    \              low[v] = std::min(low[v], low[to]);\n                } else {\n\
    \                    low[v] = std::min(low[v], ord[to]);\n                }\n\
    \            }\n            if (low[v] == ord[v]) {\n                while (true)\
    \ {\n                    int u = visited.back();\n                    visited.pop_back();\n\
    \                    ord[u] = _n;\n                    ids[u] = group_num;\n \
    \                   if (u == v) break;\n                }\n                group_num++;\n\
    \            }\n        };\n        for (int i = 0; i < _n; i++) {\n         \
    \   if (ord[i] == -1) dfs(dfs, i);\n        }\n        for (auto& x : ids) {\n\
    \            x = group_num - 1 - x;\n        }\n        return {group_num, ids};\n\
    \    }\n\n    std::vector<std::vector<int>> scc() {\n        auto ids = scc_ids();\n\
    \        int group_num = ids.first;\n        std::vector<int> counts(group_num);\n\
    \        for (auto x : ids.second) counts[x]++;\n        std::vector<std::vector<int>>\
    \ groups(ids.first);\n        for (int i = 0; i < group_num; i++) {\n        \
    \    groups[i].reserve(counts[i]);\n        }\n        for (int i = 0; i < _n;\
    \ i++) {\n            groups[ids.second[i]].push_back(i);\n        }\n       \
    \ return groups;\n    }\n\n   private:\n    int _n;\n    struct edge {\n     \
    \   int to;\n    };\n    std::vector<std::pair<int, edge>> edges;\n};\n\n}  //\
    \ namespace internal\n\n}  // namespace e6nlaq\n\n#endif  // E6NLAQ_INTERNAL_SCC_HPP\n"
  dependsOn:
  - include/e6nlaq/internal/csr.hpp
  isVerificationFile: false
  path: include/e6nlaq/internal/scc.hpp
  requiredBy:
  - include/e6nlaq/twosat.hpp
  - include/e6nlaq/scc.hpp
  - include/e6nlaq/all.hpp
  timestamp: '2025-12-09 13:48:01+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/e6nlaq/internal/scc.hpp
layout: document
redirect_from:
- /library/include/e6nlaq/internal/scc.hpp
- /library/include/e6nlaq/internal/scc.hpp.html
title: include/e6nlaq/internal/scc.hpp
---

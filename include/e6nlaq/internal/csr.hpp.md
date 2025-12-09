---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/e6nlaq/internal/csr.hpp\"\n// This file is a fork\
    \ of AtCoder Library.\n\n#ifndef E6NLAQ_INTERNAL_CSR_HPP\n#define E6NLAQ_INTERNAL_CSR_HPP\
    \ 1\n\n#include <algorithm>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ e6nlaq {\nnamespace internal {\n\ntemplate <class E>\nstruct csr {\n    std::vector<int>\
    \ start;\n    std::vector<E> elist;\n    explicit csr(int n, const std::vector<std::pair<int,\
    \ E>>& edges)\n        : start(n + 1), elist(edges.size()) {\n        for (auto\
    \ e : edges) {\n            start[e.first + 1]++;\n        }\n        for (int\
    \ i = 1; i <= n; i++) {\n            start[i] += start[i - 1];\n        }\n  \
    \      auto counter = start;\n        for (auto e : edges) {\n            elist[counter[e.first]++]\
    \ = e.second;\n        }\n    }\n};\n\n}  // namespace internal\n\n}  // namespace\
    \ e6nlaq\n\n#endif  // E6NLAQ_INTERNAL_CSR_HPP\n"
  code: "// This file is a fork of AtCoder Library.\n\n#ifndef E6NLAQ_INTERNAL_CSR_HPP\n\
    #define E6NLAQ_INTERNAL_CSR_HPP 1\n\n#include <algorithm>\n#include <utility>\n\
    #include <vector>\n\nnamespace e6nlaq {\nnamespace internal {\n\ntemplate <class\
    \ E>\nstruct csr {\n    std::vector<int> start;\n    std::vector<E> elist;\n \
    \   explicit csr(int n, const std::vector<std::pair<int, E>>& edges)\n       \
    \ : start(n + 1), elist(edges.size()) {\n        for (auto e : edges) {\n    \
    \        start[e.first + 1]++;\n        }\n        for (int i = 1; i <= n; i++)\
    \ {\n            start[i] += start[i - 1];\n        }\n        auto counter =\
    \ start;\n        for (auto e : edges) {\n            elist[counter[e.first]++]\
    \ = e.second;\n        }\n    }\n};\n\n}  // namespace internal\n\n}  // namespace\
    \ e6nlaq\n\n#endif  // E6NLAQ_INTERNAL_CSR_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: include/e6nlaq/internal/csr.hpp
  requiredBy: []
  timestamp: '2025-12-09 22:47:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/e6nlaq/internal/csr.hpp
layout: document
redirect_from:
- /library/include/e6nlaq/internal/csr.hpp
- /library/include/e6nlaq/internal/csr.hpp.html
title: include/e6nlaq/internal/csr.hpp
---

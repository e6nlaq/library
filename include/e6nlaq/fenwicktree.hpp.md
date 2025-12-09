---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: include/e6nlaq/internal/type_traits.hpp
    title: include/e6nlaq/internal/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: include/e6nlaq/all.hpp
    title: include/e6nlaq/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://en.wikipedia.org/wiki/Fenwick_tree
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ include/e6nlaq/fenwicktree.hpp: line 9: unable to process #include in #if /\
    \ #ifdef / #ifndef other than include guards\n"
  code: "// This file is a fork of AtCoder Library.\n\n#ifndef E6NLAQ_FENWICKTREE_HPP\n\
    #define E6NLAQ_FENWICKTREE_HPP 1\n\n#include <cassert>\n#include <vector>\n\n\
    #include \"e6nlaq/internal/type_traits.hpp\"\n\nnamespace e6nlaq {\n\n// Reference:\
    \ https://en.wikipedia.org/wiki/Fenwick_tree\ntemplate <class T>\nstruct fenwick_tree\
    \ {\n    using U = internal::to_unsigned_t<T>;\n\n   public:\n    fenwick_tree()\
    \ : _n(0) {}\n    explicit fenwick_tree(int n) : _n(n), data(n) {}\n\n    void\
    \ add(int p, T x) {\n        assert(0 <= p && p < _n);\n        p++;\n       \
    \ while (p <= _n) {\n            data[p - 1] += U(x);\n            p += p & -p;\n\
    \        }\n    }\n\n    T sum(int l, int r) {\n        assert(0 <= l && l <=\
    \ r && r <= _n);\n        return sum(r) - sum(l);\n    }\n\n   private:\n    int\
    \ _n;\n    std::vector<U> data;\n\n    U sum(int r) {\n        U s = 0;\n    \
    \    while (r > 0) {\n            s += data[r - 1];\n            r -= r & -r;\n\
    \        }\n        return s;\n    }\n};\n\n}  // namespace e6nlaq\n\n#endif \
    \ // E6NLAQ_FENWICKTREE_HPP\n"
  dependsOn:
  - include/e6nlaq/internal/type_traits.hpp
  isVerificationFile: false
  path: include/e6nlaq/fenwicktree.hpp
  requiredBy:
  - include/e6nlaq/all.hpp
  timestamp: '2025-12-10 00:09:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/e6nlaq/fenwicktree.hpp
layout: document
redirect_from:
- /library/include/e6nlaq/fenwicktree.hpp
- /library/include/e6nlaq/fenwicktree.hpp.html
title: include/e6nlaq/fenwicktree.hpp
---

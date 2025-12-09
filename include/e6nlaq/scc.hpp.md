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
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ include/e6nlaq/scc.hpp: line 9: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "// This file is a fork of AtCoder Library.\n\n#ifndef E6NLAQ_SCC_HPP\n#define\
    \ E6NLAQ_SCC_HPP 1\n\n#include <cassert>\n#include <vector>\n\n#include \"e6nlaq/internal/scc.hpp\"\
    \n\nnamespace e6nlaq {\n\nstruct scc_graph {\n   public:\n    scc_graph() : internal(0)\
    \ {}\n    explicit scc_graph(int n) : internal(n) {}\n\n    void add_edge(int\
    \ from, int to) {\n        int n = internal.num_vertices();\n        assert(0\
    \ <= from && from < n);\n        assert(0 <= to && to < n);\n        internal.add_edge(from,\
    \ to);\n    }\n\n    std::vector<std::vector<int>> scc() { return internal.scc();\
    \ }\n\n   private:\n    internal::scc_graph internal;\n};\n\n}  // namespace e6nlaq\n\
    \n#endif  // E6NLAQ_SCC_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: include/e6nlaq/scc.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/e6nlaq/scc.hpp
layout: document
redirect_from:
- /library/include/e6nlaq/scc.hpp
- /library/include/e6nlaq/scc.hpp.html
title: include/e6nlaq/scc.hpp
---

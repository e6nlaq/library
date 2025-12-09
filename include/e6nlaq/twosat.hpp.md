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
    \ include/e6nlaq/twosat.hpp: line 9: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "// This file is a fork of AtCoder Library.\n\n#ifndef E6NLAQ_TWOSAT_HPP\n\
    #define E6NLAQ_TWOSAT_HPP 1\n\n#include <cassert>\n#include <vector>\n\n#include\
    \ \"e6nlaq/internal/scc.hpp\"\n\nnamespace e6nlaq {\n\n// Reference:\n// B. Aspvall,\
    \ M. Plass, and R. Tarjan,\n// A Linear-Time Algorithm for Testing the Truth of\
    \ Certain Quantified Boolean\n// Formulas\nstruct two_sat {\n   public:\n    two_sat()\
    \ : _n(0), scc(0) {}\n    explicit two_sat(int n) : _n(n), _answer(n), scc(2 *\
    \ n) {}\n\n    void add_clause(int i, bool f, int j, bool g) {\n        assert(0\
    \ <= i && i < _n);\n        assert(0 <= j && j < _n);\n        scc.add_edge(2\
    \ * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));\n        scc.add_edge(2 * j + (g ?\
    \ 0 : 1), 2 * i + (f ? 1 : 0));\n    }\n    bool satisfiable() {\n        auto\
    \ id = scc.scc_ids().second;\n        for (int i = 0; i < _n; i++) {\n       \
    \     if (id[2 * i] == id[2 * i + 1]) return false;\n            _answer[i] =\
    \ id[2 * i] < id[2 * i + 1];\n        }\n        return true;\n    }\n    std::vector<bool>\
    \ answer() { return _answer; }\n\n   private:\n    int _n;\n    std::vector<bool>\
    \ _answer;\n    internal::scc_graph scc;\n};\n\n}  // namespace e6nlaq\n\n#endif\
    \  // E6NLAQ_TWOSAT_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: include/e6nlaq/twosat.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/e6nlaq/twosat.hpp
layout: document
redirect_from:
- /library/include/e6nlaq/twosat.hpp
- /library/include/e6nlaq/twosat.hpp.html
title: include/e6nlaq/twosat.hpp
---

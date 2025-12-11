---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/e6nlaq/concepts.hpp
    title: include/e6nlaq/concepts.hpp
  - icon: ':heavy_check_mark:'
    path: include/e6nlaq/imos.hpp
    title: include/e6nlaq/imos.hpp
  - icon: ':heavy_check_mark:'
    path: include/e6nlaq/imos/imos.hpp
    title: "imos\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/2879
    links:
    - https://yukicoder.me/problems/no/2879
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: e6nlaq/imos.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/2879\"\n\n#include \"\
    e6nlaq/imos.hpp\"\n\n#include <iostream>\n\nint main() {\n    int N, Q;\n    std::cin\
    \ >> N >> Q;\n\n    std::vector<int> A(N);\n    for (int i = 0; i < N; ++i) {\n\
    \        std::cin >> A[i];\n    }\n    e6nlaq::imos imos(A);\n\n    while (Q--)\
    \ {\n        int L, R;\n        std::cin >> L >> R;\n        imos.add(L - 1, R,\
    \ 1);\n    }\n\n    auto ans = imos.get();\n    for (int i = 0; i < N; ++i) {\n\
    \        std::cout << ans[i] % 2 << (i == N - 1 ? \"\\n\" : \" \");\n    }\n\n\
    \    return 0;\n}"
  dependsOn:
  - include/e6nlaq/imos.hpp
  - include/e6nlaq/imos/imos.hpp
  - include/e6nlaq/concepts.hpp
  isVerificationFile: true
  path: test/verify/imos.test.cpp
  requiredBy: []
  timestamp: '2025-12-11 23:03:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/imos.test.cpp
layout: document
redirect_from:
- /verify/test/verify/imos.test.cpp
- /verify/test/verify/imos.test.cpp.html
title: test/verify/imos.test.cpp
---

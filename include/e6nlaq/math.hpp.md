---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: include/e6nlaq/internal/math.hpp
    title: include/e6nlaq/internal/math.hpp
  - icon: ':warning:'
    path: include/e6nlaq/math/acl.hpp
    title: include/e6nlaq/math/acl.hpp
  - icon: ':warning:'
    path: include/e6nlaq/math/integer.hpp
    title: "\u7B26\u53F7\u306A\u3057\u6574\u6570\u306E\u6841\u6570\u3092\u8A08\u7B97\
      \u3057\u307E\u3059"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: include/e6nlaq/all.hpp
    title: include/e6nlaq/all.hpp
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: e6nlaq/math/acl.hpp:\
    \ line -1: no such header\n"
  code: '#include "e6nlaq/math/acl.hpp"

    #include "e6nlaq/math/integer.hpp"'
  dependsOn:
  - include/e6nlaq/math/acl.hpp
  - include/e6nlaq/internal/math.hpp
  - include/e6nlaq/math/integer.hpp
  isVerificationFile: false
  path: include/e6nlaq/math.hpp
  requiredBy:
  - include/e6nlaq/all.hpp
  timestamp: '2025-12-10 00:12:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/e6nlaq/math.hpp
layout: document
redirect_from:
- /library/include/e6nlaq/math.hpp
- /library/include/e6nlaq/math.hpp.html
title: include/e6nlaq/math.hpp
---

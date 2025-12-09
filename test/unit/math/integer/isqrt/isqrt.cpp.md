---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: include/e6nlaq/math/integer.hpp
    title: "\u7B26\u53F7\u306A\u3057\u6574\u6570\u306E\u6841\u6570\u3092\u8A08\u7B97\
      \u3057\u307E\u3059"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"test/unit/math/integer/isqrt/isqrt.cpp\"\n#define LIBTEST\n\
    #include <e6nlaq/math/integer.hpp>\n#include <iostream>\n\nint main() {\n    int\
    \ cases;\n    std::cin >> cases;\n\n    while (cases--) {\n        long long N;\n\
    \        std::cin >> N;\n\n        std::cout << e6nlaq::isqrt(N) << std::endl;\n\
    \    }\n\n    return 0;\n}\n"
  code: "#define LIBTEST\n#include <e6nlaq/math/integer.hpp>\n#include <iostream>\n\
    \nint main() {\n    int cases;\n    std::cin >> cases;\n\n    while (cases--)\
    \ {\n        long long N;\n        std::cin >> N;\n\n        std::cout << e6nlaq::isqrt(N)\
    \ << std::endl;\n    }\n\n    return 0;\n}"
  dependsOn:
  - include/e6nlaq/math/integer.hpp
  isVerificationFile: false
  path: test/unit/math/integer/isqrt/isqrt.cpp
  requiredBy: []
  timestamp: '2025-12-09 13:48:01+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/unit/math/integer/isqrt/isqrt.cpp
layout: document
redirect_from:
- /library/test/unit/math/integer/isqrt/isqrt.cpp
- /library/test/unit/math/integer/isqrt/isqrt.cpp.html
title: test/unit/math/integer/isqrt/isqrt.cpp
---
